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
int m,r,k,n,A[20][100],ans,curr_ans,taken[100],val[100],tsum,deg[20];
void f(int depth,int taken_count)
{
	if(ans==tsum)
		return;
	if(taken_count==k)
	{
		if(curr_ans>ans)
			ans=curr_ans;
		return;
	}
	if(depth==m)
	{
		return;
	}
	for (int i = 0; i < deg[depth]; ++i)
	{
		if(!taken[A[depth][i]])
			curr_ans+=val[A[depth][i]];
		taken[A[depth][i]]++;
	}
	f(depth+1,taken_count+1);
	for (int i = 0; i < deg[depth]; ++i)
	{
		taken[A[depth][i]]--;
		if(!taken[A[depth][i]])
			curr_ans-=val[A[depth][i]];
	}
	f(depth+1,taken_count);
}
int main()
{
	freopen("spojinp.txt","r",stdin);
	tsum=0;
	scanf("%d %d",&k,&r);
	scanf("%d",&m);
	int px[m],py[m];
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d",&px[i],&py[i]);
		deg[i]=0;
	}
	scanf("%d",&n);
	int sx[n],sy[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d",&sx[i],&sy[i],&val[i]);
		tsum+=val[i];
		taken[i]=0;
		for (int j = 0; j < m; ++j)
		{
			if(((sx[i]-px[j])*(sx[i]-px[j]))+((sy[i]-py[j])*(sy[i]-py[j]))<=(r*r))
			{
				A[j][deg[j]]=i;
				deg[j]++;
			}
		}
	}
	ans=0;
	curr_ans=0;
	f(0,0);
	printf("%d\n", ans);
	return 0;
}