#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> adj[n];
	queue <int> s;
	int a,b,ans=0,t=0,temp=0;
	int vis[n];vis[n-1] = 0;
	int level[n];level[n-1] = 0;
	for(int i=0;i<n-1;i++)
	{
		vis[i] = 0;
		level[i] = 0;
		cin>>a>>b;
		a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i=0;i<n;i++)
	{
		if(adj[i].size() == 1)
		{
			s.push(i);
			level[i] = 0;
			vis[i] = 1;
			break;
		}
	}
	while(!s.empty())
	{
		t= s.front();s.pop();
		for(int i=0;i<adj[t].size();i++)
		{
			if(vis[adj[t][i]] == 0)
			{
				level[adj[t][i]] = level[t] + 1;
				vis[adj[t][i]] = 1;
				s.push(adj[t][i]);
			}
		}
	}
	//cout<<"LOL"<<endl;
	for(int i=0;i<n;i++)
	{
		if(level[i] > temp)
		{
			temp = level[i];
			t = i;
		}
	}
	for(int i=0;i<n;i++)
	{
		level[i] = 0;
		vis[i] = 0;
	}
	s.push(t);
	while(!s.empty())
	{
		t= s.front();s.pop();
		for(int i=0;i<adj[t].size();i++)
		{
			if(vis[adj[t][i]] == 0)
			{
				level[adj[t][i]] = level[t] + 1;
				vis[adj[t][i]] = 1;
				s.push(adj[t][i]);
			}
		}
	}
	temp = 0;
	for(int i=0;i<n;i++)
	{
		if(level[i] > temp)
			temp = level[i];
	}
	cout<<temp;

}