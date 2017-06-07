function robot = init_robot(ID)
     % creating fields and values of the structure
      global clientID
      global vrep
      % get position 
      [~,objectHandle] = vrep.simxGetObjectHandle(clientID,ID,vrep.simx_opmode_blocking);
      [~,position]= vrep.simxGetObjectPosition(clientID,objectHandle,-1,vrep.simx_opmode_streaming ) ; 
      [~,orientation]= vrep.simxGetObjectOrientation(clientID,objectHandle,-1,vrep.simx_opmode_streaming) ;                
      x = round(position(1)) + 1; % our matrix starts from 1,1
      y = round(position(2)) + 1; % our matrix starts from 1,1
        
      f1 = 'left_motor';       v1 = [];
      f2 = 'right_motor';      v2 = [];
      f3 = 'coordinates';      v3 = [x,y];
      f4 = 'Orientation';      v4 = orientation(3);
      f5 = 'state';            v5 = [] ; % runing - disconnected - idle   
      f6 = 'last_coordinates'; v6 = [] ; 
      f7 = 'sensor_read';      v7 = [] ;  
      f8 = 'ID';               v8 = ID ;
      % creating instances from the structure
      robot = struct(f1,v1,f2,v2,f3,v3,f4,v4,f5,v5,f6,v6,f7,v7,f8,v8);
end