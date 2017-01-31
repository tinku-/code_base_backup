#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	long long int m = 1000000000 + 7;
	long long int dp[1000001];
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3;i<1000001;i++)
	{
		dp[i] = dp[i-2]*(i-1) + dp[i-1];
		dp[i] %= m;
	}
	while(t--)
	{
		int n;cin>>n;
		cout<<dp[n]<<endl;	
	}
}