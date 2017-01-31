#include <bits/stdc++.h>
using namespace std;
long long int m = 1000000000 + 7;
long long int a,b,n,x;

long long int exp(long long int a,long long int n,long long int m)
{
	long long int power = a%m;
	long long int x=1;
	long long int temp=0;
	//cout<<n<<" ";
	while(n != 0)
	{
		temp = n%2;
		n = n/2;
		if(temp == 1)
			x = (x*power)%m;
		power = (power*power)%m;
	}
	//cout<<x<<endl;
	return x;
}
int main()
{
	long long int g = 0;
	cin>>a>>b>>n>>x;
	long long ans;
	if(n == 1)
	{
		cout<<((exp(a,n,m)*x)%m + b%m)%m;
		return 0;	
	}
	ans = (exp(a,n,m)*x)%m ;
	ans += (((exp(a,n,m)-1)*b)*exp(a-1,m-2,m))%m;
	cout<<ans%m;
}