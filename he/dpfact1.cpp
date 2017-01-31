#include <bits/stdc++.h>
using namespace std;
#define MAX (1000000007)
long long int dp[500001] = {0};
int main()
{
	dp[0] = 1;
	int n;
	int t;cin>>t;
	for(int i=1;i<=99999;i++)
	{
		dp[i] = ((dp[i-1]%MAX)*(i%MAX))%MAX;
	}
	while(t--)
	{
		cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;	
}