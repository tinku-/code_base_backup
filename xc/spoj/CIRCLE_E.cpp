#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int t;
	double r1,r2,r3,ans;
	cin>>t;
	cout.precision(6);
	while(t--)
	{
		cin>>r1>>r2>>r3;
		r1=1/r1;
		r2=1/r2;
		r3=1/r3;
		ans=r1+r2+r3+2*sqrt((r1*r2)+(r1*r3)+(r2*r3));
		ans=1/ans;
		cout<<fixed<<ans<<"\n";
	}
	return 0;
}