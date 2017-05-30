function Distances =  sense(robot)
    global vrep
    global clientID
    
    % calls a threaded script in Vrep to sense the robot surroundings
    [~,~,Distances,~,~]=vrep.simxCallScriptFunction(clientID,robot.ID,vrep.sim_scripttype_childscript,'sense',[],[],[],[],vrep.simx_opmode_blocking);
end