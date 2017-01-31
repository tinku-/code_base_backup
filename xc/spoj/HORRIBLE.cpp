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
#include <cstring>
#include <queue>
using namespace std;
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
int n;
long long int BITm[100001],BITc[100001];
long long int query_m(int pos)
{
	long long int ans=0;
	while(pos>=1)
	{
		ans+=BITm[pos];
		pos-=(pos&(pos*-1));
	}
	return ans;
}
long long int query_c(int pos)
{
	long long int ans=0;
	while(pos>=1)
	{
		ans+=BITc[pos];
		pos-=(pos&(pos*-1));
	}
	return ans;
}
void update_m(int pos,long long int v)
{
	while(pos<=n)
	{
		BITm[pos]+=v;
		pos+=(pos&(pos*-1));
	}
}
void update_c(int pos,long long int v)
{
	while(pos<=n)
	{
		BITc[pos]+=v;
		pos+=(pos&(pos*-1));
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int c;
		scanf("%d %d",&n,&c);
		memset(BITm,0,sizeof(BITm));
		memset(BITc,0,sizeof(BITc));
		while(c--)
		{
			int ch;
			scanf("%d",&ch);
			if(ch)
			{
				long long int p,q;
				scanf("%lld %lld",&p,&q);
				printf("%lld\n", (query_m(q)*q)+query_c(q)-(query_m(p-1)*(p-1))-query_c(p-1));
			}
			else
			{
				long long int p,q,v;
				scanf("%lld %lld %lld",&p,&q,&v);
				update_m(p,v);
				update_c(p,(p-1)*v*-1);
				if(q<n)
				{
					update_m(q+1,v*-1);
					update_c(q+1,v*q);
				}
			}
		}
	}
	return 0;
}