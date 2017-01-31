#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 1e4 + 5;
int arr[MAX],nodes,edges;
pair <long long, pair<int, int> > p[MAX];

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
	long long int cost=0,mincost=0;
	for(int i = 0;i<edges;i++)
	{
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		if(root(x) != root(y))
		{
			mincost += cost;
			union1(x,y);
		}
	}
	return mincost;
}
int main()
{
	int x,y;
	long long int weight,cost,mincost;
	pair <long long, pair<int, int> > p[MAX];
	intializer();
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++)
	{
		cin>>x>>y>>weight;
		p[i] = make_pair(weight,make_pair(x,y));
	}
	sort(p,p+edges);
	mincost = kruskal(p);
	cout<<mincost<<endl;
}
