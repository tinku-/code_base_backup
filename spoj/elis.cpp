#include <bits/stdc++.h>	
using namespace std;
int main()
{
	int n;cin>>n;
	int sum,ans=0;
	int arr[n],dp[n+1];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	dp[0] = 1;
	for(int i=0;i<n;i++)
	{
		sum = 0;
		for(int j=0;j<i;j++)
		{
			if(arr[i] > arr[j])
				sum = max(sum,dp[j]);
		}
		dp[i] = sum + 1;
		ans = max(dp[i],ans);
	}
	cout<<ans;

}