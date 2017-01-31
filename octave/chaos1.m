x = [-0:0.01:1];
y = x;
g = 3.56.*x.*(1-x);
plot(x,y,'-b',x,g,'-b');
hold on;
%j = sin(x);
%plot(x,j);

x(1) = input('initial value :'); 
plot([x(1),x(1)],[x(1),0],'-r'); 
for i = 1:100
  x(i+1) = 3.56.*(x(i)).*(1-x(i));
  plot([x(i),x(i)],[x(i),x(i+1)],'-r'); 
  hold on;
  pause(0.1);
  plot([x(i),x(i+1)],[x(i+1),x(i+1)],'-r'); 
  hold on;
  pause(0.1);
end

