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
struct node
{
	int val,l_min;
};
node tree[65536];
int depth;
node merge_child(node &l,node &r)
{
	node ans;
	ans.val=l.val+r.val;
	ans.l_min=min(l.l_min,l.val+r.l_min);
	return ans;
}
void update(int pos)
{
	tree[pos].val*=-1;
	tree[pos].l_min*=-1;
	pos/=2;
	while(pos>0)
	{
		tree[pos]=merge_child(tree[2*pos],tree[(2*pos)+1]);
		pos/=2;
	}
}
int main()
{
	freopen("spojinp.txt","r",stdin);
	for (int test_case = 0; test_case < 10; ++test_case)
	{
		printf("Test %d:\n", test_case+1);
		int n;
		scanf("%d",&n);
		depth=0;
		while(n>(1<<depth))
		{
			depth++;
		}
		char str[n+1];
		scanf("%s",str);
		for (int i = 0; i < n; ++i)
		{
			int pos=i+(1<<depth);
			if(str[i]=='(')
			{
				tree[pos].val=1;
				tree[pos].l_min=1;
			}
			else
			{
				tree[pos].val=-1;
				tree[pos].l_min=-1;
			}
		}
		for (int i = n+(1<<depth); i < (1<<(depth+1)); ++i)
		{
			tree[i].val=0;
			tree[i].l_min=0;
		}
		for (int i = (1<<depth)-1; i > 0; --i)
		{
			tree[i]=merge_child(tree[2*i],tree[(2*i)+1]);
		}
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int x;
			scanf("%d",&x);
			if(x==0)
			{
				if(tree[1].val==0 && tree[1].l_min==0)
					printf("YES\n");
				else
					printf("NO\n");
			}
			else
			{
				update(x+(1<<depth)-1);
				// for (int i = 1; i < (1<<(depth+1)); ++i)
				// {
				// 	printf("%d %d %d\n", i,tree[i].val,tree[i].l_min);
				// }
			}
		}
	}
	return 0;
}