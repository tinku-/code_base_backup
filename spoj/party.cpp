#include <bits/stdc++.h>
using namespace std;
int dp[501][501] = {0};
//int dcost[501][501] = {0};
int mfun=0,mcost=0;
int main()
{
	int b,n;
	int cost[501],fun[501];
	while(1)
	{
		cin>>b>>n;
		if(b == 0 && n == 0)
			return 0;
		for(int i=1;i<=n;i++)
			cin>>cost[i]>>fun[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=b;j++)
			{
				if(cost[i] <= j)
				{
					if( dp[i-1][j] >= (dp[i-1][j-cost[i]] + fun[i]) )
						dp[i][j] = dp[i-1][j];
					else
						dp[i][j] = dp[i-1][j-cost[i]] + fun[i];
				}
				else
				{
						dp[i][j] = dp[i-1][j];
				}
			}
		mfun = dp[n][b];
		for(int i=b;i>0;i--)
		{
			if(dp[n][i] == mfun)
				mcost = i;
		}
		cout<<mcost<<" "<<mfun<<endl;
	}
}