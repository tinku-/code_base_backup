#include <bits/stdc++.h>
using namespace std;
int tree[1000005] = {0};
int arr[1000005] = {0};
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
		tree[node] = max(tree[2*node],max(tree[2*node] + tree[2*node+1],tree[2*node+1]));
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
	return max(max(p1,p2),p1 + p2);
}
int main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	build(1,0,n-1);
	int m,a,b;cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		cout<<query(1,0,n-1,a,b)<<endl;
	}
}