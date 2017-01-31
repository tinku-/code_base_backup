#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int root(int arr[],int i)
{
	while(arr[i] != i)
	{
		arr[i] = arr[arr[i]];
		i = arr[i];
	}
	return i;
}
void union1(int arr[],int x,int y)
{
	int root_x = root(arr,x);
	int root_y = root(arr,y);
	arr[root_y] = root_x;
}
bool find(int arr[],int i,int j)
{
	if(arr[i] == arr[j])
		return true;
	if(root(arr,i) == root(arr,j))
		return true;
	return false;
}
int main()
{
	int n,k,ans=0,x,y;
	cin>>n>>k;
	int arr[n+1];
	for(int i=0;i<=n;i++)
		arr[i] = i;
	for(int i=0;i<k;i++)
	{
		cin>>x>>y;
		union1(arr,x,y);
	}
	for(int i=1;i<=n;i++)
	{
		//cout<<arr[i]<<" ";
		if(arr[i] == i)
			ans++;
	}
	cout<<ans;
}