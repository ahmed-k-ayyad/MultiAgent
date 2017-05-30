function robot = init_robot(x,y)
     % creating fields and values of the structure
      f1 = 'left_motor';    v1 = [];
      f2 = 'right_motor';   v2 = [];
      f3 = 'coordinates';   v3 = [x,y];
      f4 = 'Orientation';   v4 = 0;
      
      % creating instances from the structure
      robot = struct(f1,v1,f2,v2,f3,v3,f4,v4);
end