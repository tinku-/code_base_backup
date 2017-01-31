% Ridam Jain 
% 2013B5A7841H

x = [-2*pi:0.01:2*pi];
y = cos(x);
g = x;
plot(x,y,'.-b',x,g,'.-b');
title('cobweb diagram for the map x_n_+_1 = cos(x_n)');
grid on, axis equal;
hold on;

x(1) = input('set initial value to :');
plot([x(1),x(1)],[x(1),0],'.-r');
hold on;
for i = 1:50
  x(i+1) = cos(x(i));
  x1 = [x(i),x(i)];
  y1 = [x(i),x(i+1)];
  plot(x1,y1,'.-r'); 
  hold on;
  pause(0.1); %comment them to remove time delay
  x2 = y1;
  y2 = [x(i+1),x(i+1)];
  plot(x2,y2,'.-r'); 
  hold on;
  pause(0.1); %comment them to remove time delay
end


