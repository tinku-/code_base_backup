#include <bits/stdc++.h>
using namespace std;
int brr[100005] = {0};
struct link
{
	long long int t;
	long long int w;
	long long int f;
};
bool acompare(link lhs, link rhs) 
{ 
	return lhs.w < rhs.w; 
}
int main()
{
	int n,m,k;cin>>n>>m>>k;
	struct link arr[m];
	struct link temp;
	int u,v,l;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>l;
		temp.t = u;
		temp.f = v;
		temp.w = l;
		arr[i] = temp;
	}
	sort(arr, arr+m, acompare);
	for(int i=0;i<k;i++)
	{
		cin>>l;
		brr[l] = 1;
	}
	for(int i=0;i<m;i++)
	{
		if(brr[arr[i].t]^brr[arr[i].f] == 1)
		{
			cout<<arr[i].w;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}