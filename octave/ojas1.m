%Write a program which 
%will determine the value of r 
%at which a period doubling bifurcation occurs 
%in the map x_n+1 = exp(-r*x_n)

%x = [-5:0.0001:5];
%r = [-5:0.0001:5];

%ezplot('exp(-r*exp(-r*x)) - x');
%
%syms x r;
%%
  

for x = 0:0.0001:1
  for r = 2:0.0001:3
    sum1 = r*r*(exp(-r*exp(-r*x)))*exp(-r*x) - 1;
		sum2 = exp(-r*exp(-r*x)) - x;
    if(abs(sum1) < 0.001 && abs(sum2) < 0.001)
      ans = r;
      break
    end
  end
end  