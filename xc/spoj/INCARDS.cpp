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
#include <map>
#include <vector>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int p,q;
		scanf("%d %d",&p,&q);
		vector < vector < pair<int,int> > > G(p),RG(p);
		int a,b,c;
		for (int i = 0; i < q; ++i)
		{
			scanf("%d %d %d",&a,&b,&c);
			G[a-1].push_back(pair <int,int> (b-1,c));
			RG[b-1].push_back(pair <int,int> (a-1,c));
		}
		long long int ans=0;
		vector <int> dist(p,1100000000),rdist(p,1100000000);
		set < pair<int,int> > A;
		A.insert(pair <int,int> (0,0));
		dist[0]=0;
		while(!A.empty())
		{
			pair <int,int> top=*A.begin();
			A.erase(A.begin());
			int v=top.second,d=top.first;
			ans+=d;
			// printf("%d %d\n", v,d);
			int d2,v2;
			for (int i = 0; i < G[v].size(); ++i)
			{
				v2=G[v][i].first;
				d2=G[v][i].second;
				if(dist[v2]>dist[v]+d2)
				{
					if(dist[v2]!=1100000000)
					{
						A.erase(A.find(pair <int,int> (dist[v2],v2)));
					}
					dist[v2]=dist[v]+d2;
					A.insert(pair <int,int> (dist[v2],v2));
				}
			}
		}
		A.clear();
		A.insert(pair <int,int> (0,0));
		rdist[0]=0;
		while(!A.empty())
		{
			pair <int,int> top=*A.begin();
			A.erase(A.begin());
			int v=top.second,d=top.first;
			ans+=d;
			// printf("%d %d\n", v,d);
			int d2,v2;
			for (int i = 0; i < RG[v].size(); ++i)
			{
				v2=RG[v][i].first;
				d2=RG[v][i].second;
				if(rdist[v2]>rdist[v]+d2)
				{
					if(rdist[v2]!=1100000000)
					{
						A.erase(A.find(pair <int,int> (rdist[v2],v2)));
					}
					rdist[v2]=rdist[v]+d2;
					A.insert(pair <int,int> (rdist[v2],v2));
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}