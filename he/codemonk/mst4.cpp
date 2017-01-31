#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int unionn = 0;
const int MAX = 4000;
const long long M = 1000000000 + 7;
typedef pair <int , int> PII;

int prims(vector <PII> adj[],bool marked[],int x)
{
	for(int i=0;i<MAX;i++)
		marked[i] = false;
	priority_queue <PII,vector<PII> > q;
	q.push(make_pair(0,x));
	PII p;
	int y;
	while(!q.empty())
	{
		p = q.top();
		q.pop();
		x = p.second;
		if(marked[x] == true)
		{
			if(p.first == 3)
				unionn++;
			//cout<<"lol"<<endl;
			ans++;
			continue;
		}
		marked[x] = true;
		for(int i=0;i<adj[x].size();i++)
		{
			y = adj[x][i].second;
			if(marked[y] == false)
				q.push(adj[x][i]);
		}

	}

}
int main()
{
	int n,m;
	int x,y,z;
	vector<PII> adj1[MAX];
	vector<PII> adj2[MAX];
	bool marked1[MAX];
	bool marked2[MAX];
	cin>>n>>m;
	while(m--)
	{
		cin>>x>>y>>z;
		if(z == 3)
		{
			adj1[x].push_back(make_pair(z,y));
			adj1[y].push_back(make_pair(z,x));
			adj2[x].push_back(make_pair(z,y));
			adj2[y].push_back(make_pair(z,x));
		}
		else if(z == 2)
		{
			adj2[x].push_back(make_pair(z,y));
			adj2[y].push_back(make_pair(z,x));
		}
		else
		{
			adj1[x].push_back(make_pair(z,y));
			adj1[y].push_back(make_pair(z,x));
		}
	}
	prims(adj1,marked1,1);
	prims(adj2,marked2,1);
	for(int i=1;i<=n;i++)
	{
		if(marked2[i] == false || marked1[i] == false)
		{
			cout<<-1;
			return 0;
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<marked1[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<marked2[i]<<" ";
	}
	*/cout<<ans-unionn/2<<endl;

}