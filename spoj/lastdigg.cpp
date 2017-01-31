#include <bits/stdc++.h>
using namespace std;
int mod_exp(long long int a,long long int b)
{
	int x;
	if(b == 0)
		return 1;
	else if(b%2 == 0)
	{
		int x = mod_exp(a,b/2);
		return ((x%10)*(x%10))%10;
	}
	else
		return ((mod_exp(a,b-1)%10)*(a%10))%10;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int a,b;cin>>a>>b;
		cout<<mod_exp(a,b)<<endl;
	}
}