#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int check(int a)
{
	int f=0;
	int i=2;
	while(i<=pow(a,0.5))
	{
		if(a%i==0){f=1;return f;}
		i++;
	}
	return f;
}
int main()
{long long int n,ans=0,t1=0,t2=0;
	cin>>n;
	for(long long int i=n;i>0;i--)
		{if(check(i)==0){ans=ans+i;}}
	cout<<"\n"<<ans<<"\n";
	return 0;
}