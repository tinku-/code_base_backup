#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;	
typedef pair<int,int> PII;
bool marked[MAX];
vector<PII> adj[MAX];

long long int prims(int x)
{
	PII p;
	int y;
	long long int mincost = 0;
	priority_queue< PII,vector<PII>,greater<PII> > pq;
	pq.push(make_pair(0,x));
	while(!pq.empty())
	{
		p = pq.top();
		pq.pop();
		x = p.second;
		if(marked[x] == true)
			continue;
		mincost += p.first;
		marked[x] = true;
		for(int i=0;i<adj[x].size();i++)
		{
			y = adj[x][i].second;
			if(marked[y] == false)
				pq.push(adj[x][i]);
		}
	}
	return mincost;
}
int main()
{
	int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
   	for(int i=0;i<edges;i++)
   	{
   		cin>>x>>y>>weight;
   		adj[x].push_back(make_pair(weight,y));
   		adj[y].push_back(make_pair(weight,x));
   	}
   	cout<<prims(1)<<endl;
}
