#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct edge
{
	int weight;
	int vertex;
};
struct graph
{
	vector <struct edge> v;
}graph[1000000];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int start,end,weigh;
		cin>>start>>end>>weigh;
		graph[start].v.edge.vertex.push_back(end);
		graph[start].v.edge.weight.push_back(weigh);
	}

}