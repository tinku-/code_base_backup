#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
	long long int n=0,w=0;cin>>n>>w;
	long long int a[2*n];
	double x=0,ans=0;
	for(int i=0;i<2*n;i++)cin>>a[i];
	sort(a,a+2*n);x=(double)w/(3*n);
    if(a[0]>=x)
    {if(a[n]>=(2*x)){ans=w;}
     else
        {ans=1.5*a[n]*n;}}
    else
    {if(a[n]>=(2*a[0])){ans=3*a[0]*n;}
     else
     	{ans=1.5*a[n]*n;}}
    cout<<fixed<<setprecision(7)<<ans;
	return 0;
}