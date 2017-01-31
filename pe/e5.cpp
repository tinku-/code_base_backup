 //2 3 5 7 11 13 17 19 
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
{
    long long int n,ans=1,t1=0,t2=0;
	cin>>n;
	//ans=2*3*5*7*11*13*17*19;
	for(long long int i=n;i>0;i--)
		{if(check(i)==0){cout<<i<<"\n";ans=ans*i;}}
	cout<<"\n"<<ans<<"\n";
	for(long long int i=n;i>0;i--)
	{
		if(__gcd(ans,i)!=i)ans=ans*i/__gcd(ans,i);
	}
	cout<<"\n"<<ans<<"\n";
	return 0;
}
//read solution please;