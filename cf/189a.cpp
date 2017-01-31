#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int n,a;

int dp[4005] = {-1000};
int main()
{
	cin>>n;
	for(;cin>>a;)
	{
		for(int i=a;i<=n;i++)
		{
			dp[i] = max(dp[i-a]+1,dp[i]);
		}
	}
	cout<<dp[n];
}