#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int t;
	double s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		cout.precision(6);
		if(s<2)
		{
			cout<<fixed<<(s/12.0)+(0.5)<<"\n";
		}
		else
		{
			cout<<fixed<<1.0-((2.0*pow(s/2.0,1.5)/3.0)/(s*s/2.0))<<"\n";
		}
	}
	return 0;
}