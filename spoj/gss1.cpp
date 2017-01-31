#include <bits/stdc++.h>
using namespace std;
int tree[1000005] = {0};
int arr[1000005] = {0};	
int left[1000005] = {0};
int right[1000005] = {0};	
void build(int node,int start,int end)
{
	if(start == end)
	{
		tree[node] = arr[start];
	}
	else
	{
		int mid = (end + start)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node] = tree[2*node] + tree[2*node+1];//,tree[2*node+1]));
	}
}
int query(int node,int start,int end,int l,int r)
{
	if(r < start || end < l)
		return 0;
	if(l<= start && end <= r)
		return tree[node];
	int mid = (start + end)/2;
	int p1 = query(2*node,start,mid,l,r);
	int p2 = query(2*node+1,mid+1,end,l,r);
	return (p1 + p2);
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++) 	
		scanf("%d",&arr[i]);
	build(1,0,n-1);
	int m,a,b;scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);a--;b--;
		printf("%d\n",query(1,0,n-1,a,b));
	}
}