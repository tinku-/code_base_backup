#include <bits/stdc++.h>
using namespace std;

int visited[40000];
int arr[40000];
void initialise()
{
	for(int i=0;i<40000;i++)
	{
		arr[i] = i;
		visited[i] = 0;
	}
}
int root(int i,int arr[])
{
	while(arr[i] != i)
	{
		arr[i] = arr[arr[i]];
		i = arr[i];
	}
	return i;
}

int union1(int x,int y,int arr[])
{
	int root_x = root(x,arr);
	int root_y = root(y,arr);
	arr[root_x] = arr[root_y];
}

bool check(int arr[],int x,int y)
{
	if(root(x,arr) == root(y,arr))
		return false;
	union1(x,y,arr);
	visited[x] = 1;
	visited[y] = 1;
	return true;
}
int main()
{
	int t,x,y,e,flag = 0;;cin>>t;
	int edges,nodes;
	//int arr[40000];
	while(t--)
	{
		flag = 0;
		pair <int,int> G[10000];
		initialise();
		cin>>nodes>>edges;
		for(int i=0;i<edges;i++)
			cin>>G[i+1].first>>G[i+1].second;
		for(int i=1;i<=nodes-1;i++)
		{
			cin>>e;
			if(check(arr,G[e].first,G[e].second) == false)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			cout<<"NO"<<endl;
		else
		{
			for(int i=1;i<=edges;i++)
				if(visited[i] == 0)
					flag = 1;

			if(flag == 0)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}