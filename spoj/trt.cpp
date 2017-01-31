#include <bits/stdc++.h>
using namespace std;
int dp[2005][2005] = {0};
int optimal(int val[],int left,int right,int j)
{
	
	if(left >= right)
	{
		dp[left][right] = val[left]*j;
		return dp[left][right];
	}
	if(dp[left+1][right] == 0)
		dp[left+1][right] = optimal(val,left+1,right,j+1);
	if(dp[left][right-1] == 0)
		dp[left][right-1] = optimal(val,left,right-1,j+1);
	dp[left][right] = max(val[left]*j + dp[left+1][right],val[right]*j + dp[left][right-1]);
	return dp[left][right];
}
int main()
{
	int n;cin>>n;
	int val[n];
	for(int i=0;i<n;i++)cin>>val[i];
	cout<<optimal(val,0,n-1,1)<<endl;
	return 0;
}