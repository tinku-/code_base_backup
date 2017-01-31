#include <iostream>
using namespace std;
long long int mod=1000000007;
long long int power(long long int a,long long int b)
{
	if(a==1)
		return 1;
	if(b==0)
		return 1;
	if(b==1)
		return a;
	long long int ans=power(a,b/2);
	ans*=ans;
	ans%=mod;
	if(b%2==1)
	{
		ans*=a;
		ans%=mod;
	}
	return ans;
}
int main()
{
	long long int n,m,k,f[1000001];
	cin>>n>>m>>k;
	f[0]=1;
	if(k>n||k>m)
	{
		cout<<"0\n";
		return 0;
	}
	for(int i=1;i<=1000000;i++)
	{
		f[i]=f[i-1]*i;
		f[i]%=mod;
	}
	//k!
	long long int ans=f[k];
	//nCk
	ans*=f[n];
	ans%=mod;
	ans*=power(f[n-k],mod-2);
	ans%=mod;
	ans*=power(f[k],mod-2);
	ans%=mod;
	//mCk
	ans*=f[m];
	ans%=mod;
	ans*=power(f[m-k],mod-2);
	ans%=mod;
	ans*=power(f[k],mod-2);
	ans%=mod;
	cout<<ans<<"\n";
	return 0;
}
