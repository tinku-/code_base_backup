#include <bits/stdc++.h>
using namespace std;
int root(int arr[],int i)
{
	while(arr[i] != i)
	{
		arr[i] = arr[arr[i]];
		i = arr[i];
	}return i;
}
int merge(int arr[],int a,int b)
{
	int root_a = root(arr,a);
	int root_b = root(arr,b);
	if(root_a == root_b)
		return 0;
	arr[root_a] = arr[root_b];
	return 0;
}
int swaping_leader(int arr[],int a)
{
	int root_a = root(arr,a);
	arr[a] = a;
	arr[root_a] = a;
}
int main()
{
	int n,q,x,a,b;
	cin>>n>>q;
	int arr[n+1];
	for(int i=1;i<=n;i++)
		arr[i] = i;
	while(q--)
	{	
		cin>>x;
		if(x == 1)
		{
			cin>>a>>b;
			merge(arr,a,b);
		}
		if(x == 2)
		{
			cin>>a;
			swaping_leader(arr,a);
		}
		if(x == 3)
		{
			cin>>b;
			cout<<root(arr,b)<<"\n";
		}
	}
}