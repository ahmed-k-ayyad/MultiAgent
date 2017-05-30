function turn_right(a)
    global clientID
    global vrep
 
    % calls a threaded script in Vrep to actuate the robot
    vrep.simxCallScriptFunction(clientID,a.ID,vrep.sim_scripttype_childscript,'move_right',[],[],[],[],vrep.simx_opmode_blocking);

end