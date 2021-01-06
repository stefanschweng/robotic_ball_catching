positions=struct();

positions.candle=[0;0;1.3320];
positions.start=[0.4;0;0.9];
positions.hand_over=[0.4;0;0.7];

% direction of the endeffector z-axis
positions.candle_p=zeros(3,1);
positions.start_p=zeros(3,1);
positions.hand_over_p=[1;0;1];

% define homogeneous transformation for candle position
positions.T_candle = trvec2tform(positions.candle');