
x = [0:0.01:3];
y = exp(-2.7183*x);
g = x;
plot(x,y,'.-b',x,g,'.-b');
title('cobweb diagram for the map x_n_+_1 = 5*cos(x_n) by algoridam');
grid on, axis equal;
hold on;

x(1) = 0.366;
plot([x(1),x(1)],[x(1),0],'.-r');
hold on;
for i = 1:50
  x(i+1) = exp(-2.7183*x(i));
  x1 = [x(i),x(i)];
  y1 = [x(i),x(i+1)];
  plot(x1,y1,'.-r'); 
  hold on;
  pause(0.3);
  x2 = y1;
  y2 = [x(i+1),x(i+1)];
  plot(x2,y2,'.-r'); 
  hold on;
  pause(0.3);
end

z = sin(5)*5;

% Ridam jain 
% 2013B5A7841H