#include <bits/stdc++.h>
using namespace std;

const int  MAX = 31400;
const long long M = 1000000000 + 7;
typedef pair<long long int, int> PII;

long long int prims(vector<PII> adj[],bool marked[],int x)
{
	for(int i=0;i<MAX;i++)
		marked[i] = false;

	PII p;
	int y;
	long long int mincost=1;
	priority_queue< PII, vector<PII>, greater<PII> > pq;
	pq.push(make_pair(1,x));
	while(!pq.empty())
	{
		p = pq.top();
		pq.pop();
		x = p.second;
		if(marked[x] == true)
			continue;
		//cout<<"cool"<<endl;
		mincost = ((mincost%M)*(p.first%M))%M;
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
	int t;cin>>t;
	int x,y;
	long long int weight;
	while(t--)
	{
		int n,m;
		vector<PII> adj[MAX];
		bool marked[MAX];
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>x>>y>>weight;
			adj[x].push_back(make_pair(weight,y));
			adj[y].push_back(make_pair(weight,x));
		}
		cout<<prims(adj,marked,1)<<endl;
	}
}