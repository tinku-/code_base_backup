#include <bits/stdc++.h>
using namespace std;
int main()
{
	int s,n;cin>>s>>n;
	int val[n+1],size[n+1];
	for(int i=1;i<=n;i++)
		cin>>size[i]>>val[i];
	int dp[n+1][s+1];
	for(int i=0;i<=n;i++)
		dp[i][0] = 0;
	for(int i=0;i<=s;i++)
		dp[0][i] = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=s;j++)
		{
			if(size[i] > j)
				dp[i][j] = dp[i-1][j];
			else 
				dp[i][j] = max((val[i] + dp[i-1][j-size[i]]),dp[i-1][j]);
		}
	}cout<<dp[n][s];

	cout<<endl;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=s;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
}