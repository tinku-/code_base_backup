#include <bits/stdc++.h>
using namespace std;
int max3(int a,int b,int c)
{
	return max(a,max(b,c));
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int ans=-1,row,col;cin>>row>>col;
		int dp[row][col];
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				cin>>dp[i][j];
		for(int i=row-2;i>=0;i--)
		{
			for(int j=0;j<col;j++)
			{
				if(j == 0)
					dp[i][j] += max(dp[i+1][j],dp[i+1][j+1]);
				else if(j == col-1)
					dp[i][j] += max(dp[i+1][j-1],dp[i+1][j]);
				else
					dp[i][j] += max3(dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]);
			}
			if(i == 0)
			{
				for(int j=0;j<col;j++)
					ans = max(ans,dp[i][j]);
			}
		}
		cout<<ans<<endl;
	}
}