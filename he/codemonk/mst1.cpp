#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int MAX = 1e6 + 5;
int arr[MAX],nodes,edges;
pair <long long, pair<int, int> > p[MAX];

bool compare(const pair<long long int, pair<int, int> >&i, const pair<long long int, pair<int, int> >&j)
{
    return i.first > j.first;
}

int intializer()
{
	for(int i=0;i<MAX;i++)
		arr[i] = i;
}

int root(int i)
{
	while(arr[i] != i)
	{
		arr[i] = arr[arr[i]];
		i = arr[i];
	}
	return i;
}
 
void union1(int x,int y)
{
	int root_x = root(x);
	int root_y = root(y);
	arr[root_x] = arr[root_y]; 
}
 
int kruskal( pair <long long, pair<int, int> > p[] )
{
	int x,y;
	long long int cost=0,maxcost=0;
	for(int i = 0;i<edges;i++)
	{
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		if(root(x) != root(y))
		{
			maxcost += cost;
			union1(x,y);
		}
	}
	return maxcost;
}
int main()
{
	int t;cin>>t;
	int x,y;
	long long int weight,cost,maxcost;
	pair <long long, pair<int, int> > p[MAX];
	while(t--)
	{
		intializer();
		//cin>>nodes>>edges;
		scanf("%d %d",&nodes,&edges);
		for(int i=0;i<edges;i++)
		{
			scanf("%d %d %lld",&x,&y,&weight);
			p[i] = make_pair(weight,make_pair(x,y));
		}
		sort(p,p+edges,compare);
		maxcost = kruskal(p);
		cout<<maxcost<<endl;
	}
}
	