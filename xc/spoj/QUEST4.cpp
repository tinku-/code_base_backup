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
using namespace std;
//s=0,t=241
int A[242][242];
bool get_path()
{
	vector <int> parent(242,-1);
	parent[0]=0;
	stack <int> dfs;
	dfs.push(0);
	while(!dfs.empty())
	{
		int top=dfs.top();
		dfs.pop();
		if(top==241)
			break;
		for (int i = 0; i < 242; ++i)
		{
			if(A[top][i] && parent[i]==-1)
			{
				parent[i]=top;
				dfs.push(i);
			}
		}
	}
	if(parent[241]==-1)
		return false;
	int pos=241;
	while(pos!=0)
	{
		A[parent[pos]][pos]--;
		A[pos][parent[pos]]++;
		pos=parent[pos];
	}
	return true;
}
int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x,y;
		for (int i = 0; i < 242; ++i)
		{
			for (int j = 0; j < 242; ++j)
			{
				A[i][j]=0;
			}
		}
		for (int i = 1; i <= 120; ++i)
		{
			A[0][i]=1;
			A[i+120][241]=1;
		}
		scanf("%d",&n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d",&x,&y);
			A[x+1][y+121]=1;
		}
		int ans=0;
		while(get_path())
		{
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}