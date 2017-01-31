#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int check(long long a)
{
	int f=0;
	long long int i=2;
	while(i<=pow(a,0.5))
	{
		if(a%i==0){f=1;return f;}
		i++;
	}
	return f;
}
int main()
{
	long long int n,x=0,y=0,ans=0;
	cin>>n;
	while(x<=n)
		{if(check(y)==0){ans=y;x++;}y++;}
	cout<<"\n"<<ans<<"\n";
	return 0;
}
