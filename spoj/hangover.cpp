#include <bits/stdc++.h>
using namespace std;
int main()
{
	double x;
	while(cin>>x && x != 0.00)
	{
		double y = 0.0;
		double i = 2.0;
		while(y < x)
		{
			y += 1/i;
			i++;
		}
		cout<<fixed<<setprecision(0);
		cout<<i-2<<" "<<"card(s)"<<endl;
	}
}