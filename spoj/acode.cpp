#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	string str1 = ("0");
	while(cin>>s && s.compare(str1) != 0 )
	{
		int n = s.size();
		long long dp[n+1];
		dp[0] = 1;
		dp[1] = 1;
		for(int i=2;i<=n;i++)
		{
			//cout<<(s[i-2]-48)*10+(s[i-1]-48)<<" ";
			if((s[i-1]-48) == 0)
				dp[i] = dp[i-2];
			else if(((s[i-2]-48)*10+(s[i-1]-48)) < 27 && (s[i-2]-48) != 0 )
				dp[i] = dp[i-1] + dp[i-2];
			else
				dp[i] = dp[i-1];
		}
		//for(int i=1;i<=n;i++)
		//	cout<<dp[i]<<" ";
		//cout<<endl;
		cout<<dp[n]<<endl;
	}
}