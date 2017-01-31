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
int main()
{
	freopen("spojinp.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		int open_cost[n],cost[n][m],value[n][m];
		for(int i=0;i<n;i++)
			scanf("%d",&open_cost[i]);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&cost[i][j]);
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&value[i][j]);
			}
		}
		vector < vector <int> >obj_best(n,vector <int> (k+1,0)),f(n+1,vector <int> (k+1,0));
		for(int i=0;i<n;i++)
		{
			for(int j=open_cost[i];j<=k;j++)
			{
				for(int l=0;l<m;l++)
				{
					if(cost[i][l]+open_cost[i]>j)
						continue;
					obj_best[i][j]=max(obj_best[i][j],obj_best[i][j-cost[i][l]]+value[i][l]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=k;j++)
			{
				f[i][j]=f[i-1][j];
				for(int l=0;l<=j;l++)
				{
					f[i][j]=max(f[i][j],f[i-1][l]+obj_best[i-1][j-l]);
				}
			}
		}
		printf("%d\n",f[n][k]);
	}
	return 0;
}