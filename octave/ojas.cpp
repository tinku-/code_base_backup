//ojas gupta
//2013B5A4891H
//sir this code will take about a minute to run 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	double sum1,sum2,x,r;
	for(int i=0;i<10000;i++)
		for(int j=0;j<40000;j++)
		{
			x = i;
			x /= 10000;
			r = j;
			r /= 10000;
			//cout<<r<<" "<<x<<endl;
			//cout<<r<<" "<<abs(sum1*1000)<<" "<<abs(sum2*1000)<<endl;
			sum1 = -r*r*(-1+2*x)*(1+2*r*(-1+x)*x) - 1;//d(f2(x))/dx - 1
			sum2 = r*r*x*(1-x)*(1-r*x*(1-x)) - x;	  //f2(x) - x 
			if(abs(sum1*1000) < 0.001 && abs(sum2*1000) < 0.001)
			{
				//cout<<r<<" "<<abs(sum1*1000)<<" "<<abs(sum2*1000)<<endl;
				cout<<"r ="<<r<<" "<<"x ="<<x<<endl;
				//return 0;
			}
		}
}