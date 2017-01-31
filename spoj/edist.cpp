#include <bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int main()
{
	int t;cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		for(int i=0;i<=b.size();i++)
			dp[0][i] = i;
		for(int i=0;i<=a.size();i++)
			dp[i][0] = i;
		for(int i=1;i<=b.size();i++)
			for(int j=1;j<=a.size();j++)
			{
				if(b[i-1] == a[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]) + 1;
			}
		
		cout<<dp[b.size()][a.size()]<<endl;
	}
}