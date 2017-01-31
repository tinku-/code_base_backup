#include <bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
set <PII> s;
int n,q;
void maxmin(int arr[],int size[],int n)
{
	set<PII> :: iterator ending = s.end(); ending--; 
	set<PII> :: iterator beginning = s.begin(); 
	cout << (*ending).first-(*beginning).first<< '\n'; 
}
int initialize(int arr[],int size[],int n)
{

	for(int i=1;i<=n;i++)
	{
		arr[i] = i;
		size[i] = 1;
		s.insert(PII(size[i],i));
	}
}
int root(int arr[],int i)
{
	while(arr[i] != i)
	{
		arr[i] = arr[arr[i]];
		i = arr[i];
	}
	return i;
}
int merge(int arr[],int size[],int x,int y)
{
	int root_x = root(arr,x);
	int root_y = root(arr,y);
	if(root_x == root_y)
		return 0;
	s.erase(PII(size[root_y],root_y));
	s.erase(PII(size[root_x],root_x));
	if(size[root_x] > size[root_y])
	{
		arr[root_y] = arr[root_x];
		size[root_x] += size[root_y];
		s.insert(PII(size[root_x],root_x));
	}
	else
	{
		arr[root_x] = arr[root_y];
		size[root_y] += size[root_x];
		s.insert(PII(size[root_y],root_y));
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	cin>>n>>q;
	int x,y;
	int arr[n+1],size[n+1];
	initialize(arr,size,n);
	while(q--)
	{
		cin>>x>>y;
		merge(arr,size,x,y);
		maxmin(arr,size,n);
	}
	return 0;
}