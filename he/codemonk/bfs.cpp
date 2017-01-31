#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int visited[100] = {0};
int dist[100] = {100};
int parent[100] = {0};
vector<int> adj[100];
	
void printpath(int x,int y)
{
	if(x == y)
		cout<<y<<endl;
	else if(parent[y] == 0)
		cout<<"no paths";
	else
		printpath(x,parent[y]);
	cout<<y<<" ";
}
void bfs(int x)
{
	queue <int> q;
	q.push(x);
	visited[x] = 1;
	dist[x] = 0;
	parent[x] = 0;
	while(!q.empty())
	{
		//cout<<"fsdfsdd";
		int p = q.front();
		q.pop();
		for(int i=0;i<adj[p].size();i++)
		{
			if(visited[adj[p][i]] == 0)
			{
				visited[adj[p][i]] = 1;
				dist[adj[p][i]] = dist[p] + 1;
				parent[adj[p][i]] = p;
				q.push(adj[p][i]);
			}
		}	
		visited[p] = 2;
		cout<<p<<" ";
	}
	cout<<endl;
}
int main()
{
	int edges,nodes,x,y,total;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++)
	{
		cin>>x>>y;
		adj[y].push_back(x);
		adj[x].push_back(y);
	}
	for(int i=1;i<=nodes;i++)
	{
		cout<<i<<" :";
		for(int j=0;j<adj[i].size();j++)
			cout<<adj[i][j]<<" ";
		cout<<endl;
	}
	int source;
	cin>>source;
	bfs(source);
	for(int i = 1;i <= nodes;i++)
		cout<<dist[i]<<" ";
	cout<<endl;
	for(int i = 1;i <= nodes;i++)
		cout<<parent[i]<<" ";
	cout<<endl;

	cin>>x>>y;
	printpath(x,y);
	return 0;	
}