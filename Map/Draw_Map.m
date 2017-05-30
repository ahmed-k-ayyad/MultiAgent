function Draw_Map

    % states:
    % zero  = unexplored
    % one   = clear
    % two   = blocked
    % three = sensor view
    % four  = occupied by robot
    
    global map
    
    figure 
    hold on
    
    for i = 1:size(map,1)
        for j = 1:size(map,2)
            if map(i,j) == 0
                plot(i,j,'ko','MarkerFaceColor','k')
            elseif map(i,j) == 1
                plot(i,j,'co','MarkerFaceColor','c')
            elseif map(i,j) == 2
                plot(i,j,'ro','MarkerFaceColor','r')
            elseif map(i,j) == 3
                plot(i,j,'go','MarkerFaceColor','g')
            elseif map(i,j) == 4
                plot(i,j,'bo','MarkerFaceColor','b')
            end
        end
    end
    axis([-1,size(map,1),-1,size(map,2)])

end