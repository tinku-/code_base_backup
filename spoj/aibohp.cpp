#include <bits/stdc++.h>
using namespace std;
int dp[6105][6105] = {0};
string reverse(string s)
{
	int start = 0;
	int end = s.size()-1;
	while(start <= end)
		swap(s[start++],s[end--]);
	return s;
}
int lcs(string a)	
{
	string b = reverse(a);
	for(int i=1;i<=a.size();i++)
		for(int j=1;j<=b.size();j++)
		{
			if(a[i-1] == b[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
		}
	return dp[a.size()][b.size()];
}
int main()
{
	string s;
	int t;cin>>t;
	while(t--)
	{
		cin>>s;
		cout<<s.size()-lcs(s)<<endl;
	}
}