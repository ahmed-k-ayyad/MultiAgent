
global clientID
global vrep
    
vrep=remApi('remoteApi');
vrep.simxFinish(-1); 
 
clientID=vrep.simxStart('127.0.0.1',19999,true,true,5000,5);

if (clientID>-1)
      disp('Connected')
      
      % Robot construction
      a = init_robot(0,0);
      
      % Handles
      [~,a.left_motor]=vrep.simxGetObjectHandle(clientID,'Pioneer_p3dx_rightMotor',vrep.simx_opmode_blocking );
      [~,a.right_motor]=vrep.simxGetObjectHandle(clientID,'Pioneer_p3dx_leftMotor',vrep.simx_opmode_blocking );
      
      % enable the synchronous mode on the client:
      vrep.simxSynchronousTrigger(clientID);
      
      % core system      
      for i = 1:10
          turn_right(a);
          turn_left(a);
          pause(0.1);
      end
      % end simulation
       vrep.simxFinish(-1); 

  vrep.delete();
      
end