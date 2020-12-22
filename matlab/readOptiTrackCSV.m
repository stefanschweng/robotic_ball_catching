%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  function data = readOptiTrackCSV(filename, header, varnames)
%
%  purpose :    generate struct from CSV file (an export of
%               Motive v2.1.1 Final/OptiTrack)
%
% information:  uses csvread(), therefore empty entries are zeros
%               tested for Matlab 2016b, 2018b
%               rotation matrix is always saved as 
%                         [X; Y; Z] or [X; Y; Z; W]
%               position matrix is always saved as 
%                         [X; Y; Z]
%
% examples:     dat = readOptiTrackCSV(mfilename, true, [])
%               dat = readOptiTrackCSV(mfilename, false, ["Frame" "Time" "Name_x" "Name_Y" "Name_Z"]) CSV-Export without Header
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  input   arguments
%     filename: string with file name or full path
%     header: 	true|false, true: header was included in the export
%     varnames: if header=false, variable names are necessary, 
%               a minimum of 5 names is a must have
%               e.g. ["frame" "time" "HugoX" "HugoY" "HugoZ"]
%               if header=true, varnames is not used, e.g. []
%
%  output   arguments
%     data:     a struct with the following composition
%               data.info.<header information>
%                   .Time 
%                   .Frames
%                   .RB.<Rigid Body Name>.<Pos|Rot> as [X; Y; Z] or [X; Y; Z; W]
%                                        .Mean_Marker_Error  
%                                        .ID 
%                   .RB_Marker.<Rigid Body Name>.<Marker1|2|...|N>.Pos as [X; Y; Z]
%                   .RB_Marker.<Rigid Body Name>.<Marker1|2|...|N>.Marker_Quality
%                   .RB_Marker.<Rigid Body Name>.<Marker1|2|...|N>.ID
%                   .Marker.<Rigid Body Name>.<Marker1|2|...|N>.ID
%                                                              .Pos as [X; Y; Z]
%                   etc.
%
%   Author: Robert Sturmlechner
%   MatrNr: 00928818
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TODO
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function data = readOptiTrackCSV(filename, header, varnames)

%% check inputs

if ~header
    if isempty(varnames)
         ME = MException('readOptiTrackCSV:WrongInput', ...
            'Input "varnames" is empty!');
        throw(ME)
    elseif ~isstring(varnames)
         ME = MException('readOptiTrackCSV:WrongInput', ...
            'Wrong data type (%s) of input "varnames", must be a string array', ...
            class(varnames));
        throw(ME)
    elseif length(varnames)<5
        ME = MException('readOptiTrackCSV:WrongInput', ...
            'Wrong length of input "varnames", must be at least of size five (Frame#, Time, Marker(X, Y, Z))');
        throw(ME)
    end
       
end


%% read Data

if header
    % CSV Format of OptiTrack Export (see
    % https://v21.wiki.optitrack.com/index.php?title=Data_Export:_CSV)
    %
    % 1st row 	General information about the Take and export settings. Included information are: format version of the CSV export, name of the TAK file, the captured frame rate, the export frame rate, capture start time, number of total frames, rotation type, length units, and coordinate space type.
    % 2nd row 	Empty
    % 3rd row 	Displays which data type is listed in each corresponding column. Data types include raw marker, rigid body, rigid body marker, bone, bone marker, or unlabeled marker. Read more about Marker Types.
    % 4th row 	Includes marker or asset labels for each corresponding data set.
    % 5th row 	Displays marker ID.
    % 6th and 7th row 	Includes header label on which data is included in the column: position and orientation on X/Y/Z. 

    % read data
    %     rdata = csvread(filename,7,0); % changes empty cells to 0.0 not NaN
    file_data = importdata(filename); % changes empty cells to NaN
    
    % catch importdata() size problems
    header_size = size(file_data.textdata);
    data_size = size(file_data.data);
    % catch empty header name columns
    header_name_size = length(split(file_data.textdata{5, 1}, ','));  
    if ~(header_size(2)==header_name_size)
        file_data.textdata = [file_data.textdata, cell(header_size(1), header_name_size-header_size(2))];
        header_size = size(file_data.textdata);
    end
     % columns at the right side are ignored by importdata() if empty
    diff_columns = header_size(2)-data_size(2);
    
    % catch not imported empty columns
    if diff_columns==0 % no columns were excluded
        rdata = file_data.data;
    elseif diff_columns>0 % empty columns were ignored by importdata()
        rdata = [file_data.data, NaN([data_size(1) diff_columns])];
    else
        % other situations
        rdata = NaN(size(file_data.textdata));
    end

    % read header information
    fileID = fopen(filename);

    % read first line: 
    tline = fgetl(fileID);
    sLine = strsplit(tline,',');
    data.info.cframe_rate.Data = str2double(sLine{find(strcmp(sLine,'Capture Frame Rate'))+1});
    data.info.cframe_rate.description = 'Captured Frame Rate';
    data.info.exp_frame_rate.Data = str2double(sLine{find(strcmp(sLine,'Export Frame Rate'))+1});
    data.info.exp_frame_rate.description = 'Export Frame Rate';
    data.info.frame_cnt.Data = str2num(sLine{find(strcmp(sLine,'Total Frames in Take'))+1});
    data.info.frame_cnt.description = 'Total Frames in Take';
    data.info.exp_frame_cnt.Data = str2num(sLine{find(strcmp(sLine,'Total Exported Frames'))+1});
    data.info.exp_frame_cnt.description = 'Total Exported Frames';
    data.info.rot_type.Data = sLine{find(strcmp(sLine,'Rotation Type'))+1};
    data.info.rot_type.description = 'Rotation Type';
    data.info.length_unit.Data = sLine{find(strcmp(sLine,'Length Units'))+1};
    data.info.length_unit.description = 'Length Units';
    data.info.coord_space.Data = sLine{find(strcmp(sLine,'Coordinate Space'))+1};
    data.info.coord_space.description = 'Coordinate Space';
    
    if ~(data.info.exp_frame_cnt.Data==data.info.frame_cnt.Data)
        warning('readOptiTrackCSV:ShortExport','The exported frame count (%d) does not match the recorded frame count (%d).', data.info.exp_frame_cnt.Data, data.info.frame_cnt.Data)
    end

    % read second line: (empty line)
    tline = fgetl(fileID);

    % read third line:
    tline = (fgetl(fileID));
    sLine3 = strsplit(tline,',');
    sLine3 = strrep(sLine3,' ','_');
    sLine3 = strrep(sLine3,'Rigid_Body','RB');
    
    % read fourth line:
    tline = (fgetl(fileID));
    sLine4 = split(tline,',');
    sLine4 = strrep(sLine4,' ','_');

    % read fifth line:
    tline = (fgetl(fileID));
    sLine5 = split(tline,',');

    % read sixth line:
    tline = (fgetl(fileID));
    sLine6 = split(tline,',');
    sLine6 = strrep(sLine6,' ','_');
    sLine6 = strrep(sLine6, 'Position', 'Pos');
    sLine6 = strrep(sLine6, 'Rotation', 'Rot');
    
    % read seventh line:
    tline = (fgetl(fileID));
    sLine7 = split(tline,',');
    
    fclose(fileID);
    
    % get all columns before a marker/rigid body
    pos = find(sLine6==string()); 
    
    % generate struct tree and set data
    for i=max(pos)+1:length(sLine7)
        sLine3{i} = checkChangeVarName(sLine3{i});
        sLine6{i} = checkChangeVarName(sLine6{i});
        
         % catch ""<Rigid Body Name>:Marker<Number>"", e.g. "Robo_Base:Marker4"
        if strfind(sLine4{i},':')>0
            sLine4_sub = split(sLine4{i},':');
            sLine4_sub{1} = checkChangeVarName(sLine4_sub{1});
            sLine4_sub{2} = checkChangeVarName(sLine4_sub{2}); 
            
            % catch empty cell
            if sLine7{i}==string() %isempty() or ~length() does not work
                data.(sLine3{i}).(sLine4_sub{1}).(sLine4_sub{2}).(sLine6{i}) = rdata(:,i);
            else
                sLine7{i} = checkChangeVarName(sLine7{i});
                if strcmp(sLine6{i},'Pos') || strcmp(sLine6{i},'Rot')
                    % generate rot/pos matrix if it does not exists
                    if ~(isfield(data,(sLine3{i})) && isfield(data.(sLine3{i}),(sLine4_sub{1})) && isfield(data.(sLine3{i}).(sLine4_sub{1}),(sLine4_sub{2})) && isfield(data.(sLine3{i}).(sLine4_sub{1}).(sLine4_sub{2}), (sLine6{i})))
                        if strcmp(data.info.rot_type.Data, 'Quaternion') && strcmp(sLine6{i},'Rot')
                            data.(sLine3{i}).(sLine4_sub{1}).(sLine4_sub{2}).(sLine6{i}) = zeros(4, data_size(1));
                        else
                            data.(sLine3{i}).(sLine4_sub{1}).(sLine4_sub{2}).(sLine6{i}) = zeros(3, data_size(1));
                        end
                    end
                    % add data to the correct column
                    switch sLine7{i}
                        case 'X'
                            data.(sLine3{i}).(sLine4_sub{1}).(sLine4_sub{2}).(sLine6{i})(1,:) = rdata(:,i);
                        case 'Y'
                            data.(sLine3{i}).(sLine4_sub{1}).(sLine4_sub{2}).(sLine6{i})(2,:) = rdata(:,i);
                        case 'Z'
                            data.(sLine3{i}).(sLine4_sub{1}).(sLine4_sub{2}).(sLine6{i})(3,:) = rdata(:,i);
                        case 'W'
                            data.(sLine3{i}).(sLine4_sub{1}).(sLine4_sub{2}).(sLine6{i})(4,:) = rdata(:,i);
                    end
                else
                    data.(sLine3{i}).(sLine4_sub{1}).(sLine4_sub{2}).(sLine6{i}).(sLine7{i}) = rdata(:,i);
                end
            end
            
            data.(sLine3{i}).(sLine4_sub{1}).(sLine4_sub{2}).ID = erase(sLine5{i},'"');
        else
            sLine4{i} = checkChangeVarName(sLine4{i});
            
            % catch empty cell
            if sLine7{i}==string() %isempty() or ~length() does not work
                data.(sLine3{i}).(sLine4{i}).(sLine6{i}) = rdata(:,i);
            else
                sLine7{i} = checkChangeVarName(sLine7{i});
                if strcmp(sLine6{i},'Pos') || strcmp(sLine6{i},'Rot')
                    % generate rot/pos matrix if it does not exists
                    if ~(isfield(data,(sLine3{i})) && isfield(data.(sLine3{i}),(sLine4{i})) && isfield(data.(sLine3{i}).(sLine4{i}), (sLine6{i})))
                        if strcmp(data.info.rot_type.Data, 'Quaternion') && strcmp(sLine6{i},'Rot')
                            data.(sLine3{i}).(sLine4{i}).(sLine6{i}) = zeros(4, data_size(1));
                        else
                            data.(sLine3{i}).(sLine4{i}).(sLine6{i}) = zeros(3, data_size(1));
                        end
                    end
                    % add data to the correct row
                    switch sLine7{i}
                        case 'X'
                            data.(sLine3{i}).(sLine4{i}).(sLine6{i})(1,:) = rdata(:,i);
                        case 'Y'
                            data.(sLine3{i}).(sLine4{i}).(sLine6{i})(2,:) = rdata(:,i);
                        case 'Z'
                            data.(sLine3{i}).(sLine4{i}).(sLine6{i})(3,:) = rdata(:,i);
                        case 'W'
                            data.(sLine3{i}).(sLine4{i}).(sLine6{i})(4,:) = rdata(:,i);
                    end
                else
                    data.(sLine3{i}).(sLine4{i}).(sLine6{i}).(sLine7{i}) = rdata(:,i);
                end
            end      
            data.(sLine3{i}).(sLine4{i}).ID = erase(sLine5{i},'"');
        end    
    end
else
    % read data
%     rdata = csvread(filename,0,0); % changes empty cells to 0.0 not NaN
    rdata = importdata(filename); % changes empty cells to NaN
    sLine7 = varnames;
    % get all columns before a marker/rigid body: Framenumber, Time
    pos = 2;
    
    % generate struct tree and set data
    for i=max(pos)+1:length(sLine7)
        sLine7{i} = checkChangeVarName(sLine7{i});
        data.(sLine7{i}) = rdata(:,i);
    end
end
    

for i=1:max(pos)
    name = split(sLine7{i},' '); % captures 'Time (Seconds)' -> only use 'Time'
    name = checkChangeVarName(name(1));
    data.(name) = rdata(:,i)'; % = zeros(1, length(C3));
end

end

function varname = checkChangeVarName(newfieldname) % copy from dspace2structNew.m, Bernhard Bischof 2019

% fgetl() imports strings with special characters, e.g. :, with additional double quotes
% double quotes are not valid characters for a variable name
varname = erase(newfieldname,'"'); 

if(isvarname(varname) == 0)

    varname = char(varname);
    
    test = isstrprop(varname,'alphanum');
    test(strfind(varname,'_')) = true; % underscore is a valid character but not an alphanum char
    
    % first bad char
    bad_start = find(~test);
    
    if bad_start % if the 'bad' character is at position 1, wherefore an exception ' Index exceeds array bounds.' would be thrown
        varname = varname(2:end);
    else
        varname = varname(test); % delete all non alphanumeric characters
    end
    
    if(isvarname(varname) == 0)
        varname = varname(2:end); % delete numbers at the start of the varname
    end
    
end

end
