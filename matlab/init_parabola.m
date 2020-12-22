% read data from csv
dat = readOptiTrackCSV('../motive_exports/26092020/marker1035.csv', true, []);

range = 3238:1:3483;

marker_pos = dat.Marker.Unlabeled_1035.Pos(1:3,range);

x = marker_pos(1,1:size(marker_pos,2));
y = marker_pos(2,1:size(marker_pos,2));
z = marker_pos(3,1:size(marker_pos,2));

% move coordinates
x = x-0.3;
y = y-1;
% z = z;

optitrack_data=struct();
optitrack_data.x = x;
optitrack_data.y = y;
optitrack_data.z = z;

clear marker_pos range dat x y z