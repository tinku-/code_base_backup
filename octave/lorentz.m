# In this example the "Lorenz attractor" implementation is solved
 # and the results are plot in a figure after solving. Read about
 # the Lorenz attractor at
 #   http://en.wikipedia.org/wiki/Lorenz_equation
 # 
 # The upper left subfigure shows the three results of the integration
 # over time. The upper right subfigure shows the force f in a two
 # dimensional (x,y) plane as well as the lower left subfigure shows
 # the force in the (y,z) plane. The three dimensional force is plot
 # in the lower right subfigure.

 

 A = odeset ('InitialStep', 1e-3, 'MaxStep', 1e-1);
 [t, y] = ode54 (@florenz, [0 25], [3 15 1], A);

 subplot (2, 2, 1); grid ('on'); 
   plot (t, y(:,1), '-b', t, y(:,2), '-g', t, y(:,3), '-r');
   legend ('f_x(t)', 'f_y(t)', 'f_z(t)');
 subplot (2, 2, 2); grid ('on'); 
   plot (y(:,1), y(:,2), '-b');
   legend ('f_{xyz}(x, y)');
 subplot (2, 2, 3); grid ('on'); 
   plot (y(:,2), y(:,3), '-b');
   legend ('f_{xyz}(y, z)');
 subplot (2, 2, 4); grid ('on');
   plot3 (y(:,1), y(:,2), y(:,3), '-b');
   legend ('f_{xyz}(x, y, z)');