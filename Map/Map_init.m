function Map_init()

% states:
% zero  = unexplored
% one   = clear
% two   = blocked
% three = sensor view
% four  = occupied by robot

global map

map = zeros(50,50);
end