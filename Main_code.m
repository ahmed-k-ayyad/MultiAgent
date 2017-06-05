
global clientID
global vrep
    
vrep=remApi('remoteApi');
vrep.simxFinish(-1); 
 
clientID=vrep.simxStart('127.0.0.1',19999,true,true,5000,5);

if (clientID>-1)
      disp('Connected')
      
      % Robot construction
      a = init_robot(0,0);
      b = init_robot(10,10);
      
      % Handles
      a.ID = 'Pioneer_p3dx';
      
      b.ID = 'Pioneer_p3dx#0';
      
      % enable the synchronous mode on the client:
      vrep.simxSynchronousTrigger(clientID);
      
      % core system      
      d1 = sense(a);
      d2 = sense(b);
      % end simulation
       vrep.simxFinish(-1); 

  vrep.delete();
      
end
