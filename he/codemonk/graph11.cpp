#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int visited[100005] = {0};
long long int arr[100005] = {0};
long long int sum = 0;

void dfs(int n,vector<int> adj[])
{
	visited[n] = 1;
	sum += arr[n];
	//cout<<n<<":"<<sum<<" ";
	for(int i=0;i<adj[n].size();i++)
	{
		if(visited[adj[n][i]] == 0)
			dfs(adj[n][i],adj);
	}
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		vector<int> adj[100005];
		for(int i=0;i<100005;i++)
		{
			arr[i] = 0;
			visited[i] = 0;
		}
		long long int ans = -1;
		int n,m,x,y;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
		sum = 0;
		for(int i=1;i<=n;i++)
		{
			if(visited[i] == 0)
			{
				dfs(i,adj);
				//cout<<"lol"<<sum<<"lol"<<endl;
				ans = max(sum,ans);
				sum = 0;
			}
		}
		cout<<ans<<endl;
	}
}