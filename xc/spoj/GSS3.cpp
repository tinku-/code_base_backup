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
int depth;
struct node
{
	long long int tot_sum,l_sum,r_sum,best_sum;
};
node identity,tree[131072];
void set_identity()
{
	identity.tot_sum=0;
	identity.l_sum=-10000000000ll;
	identity.r_sum=-10000000000ll;
	identity.best_sum=-10000000000ll;
}
node merge_child(node &l,node &r)
{
	node n;
	n.tot_sum=l.tot_sum+r.tot_sum;
	n.l_sum=max(l.l_sum,l.tot_sum+r.l_sum);
	n.r_sum=max(r.r_sum,r.tot_sum+l.r_sum);
	n.best_sum=max(max(l.best_sum,r.best_sum),l.r_sum+r.l_sum);
	return n;
}
void make_leaf(int pos,long long int val)
{
	pos+=(1<<depth);
	tree[pos].tot_sum=val;
	tree[pos].l_sum=val;
	tree[pos].r_sum=val;
	tree[pos].best_sum=val;
}
node range_query(int root,int l_most,int r_most,int u,int v)
{
	int l_child=root*2;
	int r_child=l_child+1;
	if(u<=l_most && r_most<=v)
		return tree[root];
	int mid=(l_most+r_most)/2;
	node l=identity,r=identity;
	if(u<=mid)
		l=range_query(l_child,l_most,mid,u,v);
	if(v>mid)
		r=range_query(r_child,mid+1,r_most,u,v);
	node n=merge_child(l,r);
	return n;
}
void update(int pos,long long int val)
{
	make_leaf(pos,val);
	pos+=(1<<depth);
	while(pos>0)
	{
		pos/=2;
		tree[pos]=merge_child(tree[pos*2],tree[(pos*2)+1]);
	}
}
int main()
{
	freopen("spojinp.txt","r",stdin);
	set_identity();
	int n;
	long long int x;
	scanf("%d",&n);
	depth=0;
	while((1<<depth)<n)
	{
		depth++;
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld",&x);
		make_leaf(i,x);
	}
	for (int i = (1<<depth)-1; i > 0; --i)
	{
		tree[i]=merge_child(tree[2*i],tree[(2*i)+1]);
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int ch,l,r;
		scanf("%d %d %d",&ch,&l,&r);
		if(ch)
		{
			l--;
			r--;
			node ans=range_query(1,(1<<depth),(1<<(depth+1))-1,l+(1<<depth),r+(1<<depth));
			printf("%lld\n", ans.best_sum);
		}
		else
		{
			l--;
			update(l,r);
		}
	}
	return 0;
}