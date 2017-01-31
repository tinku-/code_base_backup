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
double f[551][3301];
int main()
{
	freopen("input.txt","r",stdin);
	f[0][0]=100.0;
	for (int i = 1; i <= 550; ++i)
	{
		for (int j = i; j <= 6*i; ++j)
		{
			for (int k = 1; k <= 6; ++k)
			{
				if(j-k<0)
					break;
				f[i][j]+=f[i-1][j-k];
			}
			f[i][j]/=6.0;
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		if(n>550 || k>6*n || k<n)
			printf("0\n");
		else
		{
			int ans=floor(f[n][k]);
			printf("%d\n", ans);
		}
	}
	return 0;
}