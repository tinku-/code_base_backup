#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;
int parent[20001],dist[20001];
void find_parent(int pos)
{
	if(parent[pos]==pos)
		return;
	find_parent(parent[pos]);
	dist[pos]+=dist[parent[pos]];
	parent[pos]=parent[parent[pos]];
}
int main()
{
	freopen("spojinp.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i)
		{
			parent[i+1]=i+1;
			dist[i+1]=0;
		}
		char ch;
		int a,b;
		while(true)
		{	
			scanf(" %c",&ch);
			if(ch=='I')
			{
				scanf("%d %d",&a,&b);
				parent[a]=b;
				dist[a]+=abs(a-b)%1000;
			}
			else if(ch=='E')
			{
				scanf("%d",&a);
				find_parent(a);
				printf("%d\n", dist[a]);
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}