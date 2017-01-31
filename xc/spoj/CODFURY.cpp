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
int main()
{
	freopen("spojinp.txt","r",stdin);
	int t,n,m,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		int pre_sum[n+1];
		pre_sum[0]=0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d",&x);
			pre_sum[i]=pre_sum[i-1]+x;
		}
		int ans=0,anslen=0,f=1,l=1;
		while(l<=n)
		{
			if(pre_sum[l]-pre_sum[f-1]>m)
			{
				f++;
			}
			else
			{
				if(l+1-f>anslen || (l+1-f==anslen && pre_sum[l]-pre_sum[f-1]<ans))
				{
					ans=pre_sum[l]-pre_sum[f-1];
					anslen=l+1-f;
				}
				l++;
			}
		}
		printf("%d %d\n", ans,anslen);
	}
	return 0;
}