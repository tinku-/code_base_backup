#include <bits/stdc++.h>
using namespace std;
long long int dp[10004] = {0};
	long long int value[10004] = {0};
int main()
{
	int t,n,j=1;cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>value[i];
			dp[i] = 0;
		}
		for(int i=1;i<=n;i++)
		{
			if(i == 1)
				dp[i] = value[i];
			else
				dp[i] = max(dp[i-1],value[i] + dp[i-2]);
		}
		cout<<"Case "<<j++<<": "<<dp[n]<<endl;
	}
}