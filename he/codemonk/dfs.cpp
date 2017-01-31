#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
int visited[100] = {0};
vector<int> adj[100]; 
void dfs(int x)
{
	visited[x] = 1;
	cout<<x<<" ";
	for(int i = 0;i < adj[x].size();i++)
	{
		if(visited[adj[x][i]] == 0)
			dfs(adj[x][i]);
	}
}
int main()
{
	int nodes,edges,x,y,connectedcomponents=0;
	cin>>nodes>>edges;
	for(int i=0;i < edges;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=1;i<=nodes;i++)
	{
		cout<<" "<<i<<" :";
		for(int j=0;j < adj[i].size();j++)
			cout<<adj[i][j]<<" ";
		cout<<endl;
	}
	for(int i=1;i<=nodes;i++)
	{
		if(visited[i] == 0)
		{	
			dfs(i);
			connectedcomponents++;
		}
	}
	cout<<endl<<connectedcomponents<<endl;
}