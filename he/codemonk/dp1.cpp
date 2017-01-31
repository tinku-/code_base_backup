#include <bits/stdc++.h>
using namespace std;
long long int min3(long long int a,long long int b,long long int c)
{
	return min(a,min(b,c));
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		long long int dp[n][3];
		long long int arr[n][3];
		for(int i=0;i<n;i++)
			cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
		dp[0][0] = arr[0][0];dp[0][1] = arr[0][1];dp[0][2] = arr[0][2];
		//dp[0][1] = dp[0][2] = dp[0][0] = min3(arr[0][0],arr[0][1],arr[0][2]);
		for(int i=1;i<n;i++)
		{
				dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + arr[i][0];
				dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + arr[i][1];
				dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + arr[i][2];
				//cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
		}
		cout<<min3(dp[n-1][0],dp[n-1][1],dp[n-1][2]);
		cout<<endl;
	}
	return 0;
}