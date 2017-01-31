#include <iostream>
#include <queue>
#include <stack>
using namespace std;
vector<int> adj[100005];
int visited[100005] = {0};
long long int arr[100005] = {0};
long long int sum = 0;
long long int dfs(int n)
{
	visited[n] = 1;
	for(int i=0;i<adj[n].size();i++)
	{
		if(visited[adj[n][i]] == 0)
		{
			sum += arr[adj[n][i]-1];
			dfs(adj[n][i]);
		}
	}
	return sum;
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		long long int ans = -1;
		sum = 0;
		int n,m,x,y;
		for(int i=0;i<m;i++)
		{
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(visited[i] == 0)
			{
				dfs(i);
				ans = max(sum,ans);
				sum = 0;
			}
		}
		cout<<ans;
	}
}