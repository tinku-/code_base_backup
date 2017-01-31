#include <bits/stdc++.h>
#define MAX 10001	
using namespace std;
int primatic[MAX] = {0};
int dp[MAX];
void pcheck()
{
	int i = 2;
	while(i*i <= MAX)
	{
		if(primatic[i] == 0)
		{
			for(int j=i*i;j<=MAX;j+=i)
				primatic[j] = 1;
		}
		i++;
	}
	i = 2;
	while( pow(i,i) <= MAX)
	{
		if(primatic[i] == 0)
			primatic[(int)pow(i,i)] = 2;
		i++;
	}

	std::vector<int> v;
	for(int i=2;i<=MAX;i++)
	{
		dp[i] = MAX;
		if(primatic[i] != 1)
			v.push_back(i);
	}

	dp[0] = dp[1] = dp[2] = 1;
	for(int i=2;i<=MAX;i++)
	{
		if(primatic[i] != 1)
		{
			dp[i] = 1;
			continue;
		}
		for(int j=0;j<v.size();j++)
		{
			if(i >= v[j])
				dp[i] = min(dp[i],dp[i-v[j]] + 1);
		}
	}
}
int main()
{
	pcheck();
	int t,n;cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<dp[n]<<endl;
	}
}