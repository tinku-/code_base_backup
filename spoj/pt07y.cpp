#include <bits/stdc++.h>
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
int unioun1(int arr[],int size[],int a,int b)
{
	int A = root(arr,a);
	int B = root(arr,b);
	if(size[A] > size[B])
	{
		arr[B] = arr[A];
		size[A] += size[B];
	}
	else
	{
		arr[A] = arr[B];
		size[B] += size[A];
	}
}
int main()
{
	int n,m,a,b,temp=0,flag = 0;
	cin>>n>>m;
	int arr[n],size[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = i;
		size[i] = 1;
	}
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		a--;b--;
		if(root(arr,a) == root(arr,b))
			flag = 1;
		else
			unioun1(arr,size,a,b);
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i] == i)
			temp++;
	}
	if(temp == 1 && flag == 0 && m == n-1)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}