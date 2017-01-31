#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int t;
	double p0,p1,p2,t1,t2;
	cin>>t;
	cout.precision(2);
	for(int i=1;i<=t;i++)
	{
		cin>>p0>>p1>>t1>>p2;
		t2=t1*log(p2/p0)/log(p1/p0);
		cout<<"Scenario #"<<i<<": "<<fixed<<t2<<"\n";
	}
	return 0;
}