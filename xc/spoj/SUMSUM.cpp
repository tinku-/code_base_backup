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
	int one_count[28];
};
node identity,tree[262144];
int depth;
void make_leaf(int pos,int val)
{
	pos+=(1<<depth);
	for (int i = 0; i < 28; ++i)
	{
		if(val & (1<<i))
			tree[pos].one_count[i]=1;
		else
			tree[pos].one_count[i]=0;
	}
}
node merge(node &a,node &b)
{
	node ans;
	for (int i = 0; i < 28; ++i)
	{
		ans.one_count[i]=a.one_count[i]+b.one_count[i];
	}
	return ans;
}
void update(int pos,int val)
{
	make_leaf(pos,val);
	pos+=(1<<depth);
	while(pos>=1)
	{
		pos/=2;
		tree[pos]=merge(tree[2*pos],tree[(2*pos)+1]);
	}
}
node range_query(int root,int lmchild,int rmchild,int u,int v)
{
	if(u<=lmchild && rmchild<=v)
		return tree[root];
	int mid=(lmchild+rmchild)/2;
	node l=identity,r=identity;
	if(u<=mid)
		l=range_query(2*root,lmchild,mid,u,v);
	if(v>mid)
		r=range_query((2*root)+1,mid+1,rmchild,u,v);
	return merge(l,r);
}
int main()
{
	freopen("spojinp.txt","r",stdin);
	for (int i = 0; i < 28; ++i)
	{
		identity.one_count[i]=0;
	}
	int n,q,x;
	scanf("%d %d",&n,&q);
	depth=0;
	while(n>(1<<depth))
	{
		depth++;
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&x);
		make_leaf(i,x);
	}
	for (int i = n+(1<<depth); i < (1<<(depth+1)); ++i)
	{
		tree[i]=identity;
	}
	for (int i = (1<<depth)-1; i >= 1; --i)
	{
		tree[i]=merge(tree[2*i],tree[(2*i)+1]);
	}
	while(q--)
	{
		int ch;
		scanf("%d",&ch);
		if(ch==1)
		{
			int pos,val;
			scanf("%d %d",&val,&pos);
			pos--;
			update(pos,val);
		}
		else
		{
			char op[10];
			int p1,p2;
			scanf("%s %d %d",op,&p1,&p2);
			if(p1==p2)
			{
				printf("0\n");
				continue;
			}
			p1--;
			p2--;
			long long int oc,zc,tot=p2+1-p1;
			node ans=range_query(1,(1<<depth),(1<<(depth+1))-1,p1+(1<<depth),p2+(1<<depth));
			long long int fans=0;
			for (int i = 0; i < 28; ++i)
			{
				oc=ans.one_count[i];
				zc=tot-oc;
				switch(op[0])
				{
					case 'X':fans+=((oc*zc)<<i);
							break;
					case 'O':fans+=(((oc*(oc-1)/2)+(oc*zc))<<i);
							break;
					case 'A':fans+=((oc*(oc-1)/2)<<i);
							break;
				}
			}
			printf("%lld\n", fans);
		}
	}
	return 0;
}