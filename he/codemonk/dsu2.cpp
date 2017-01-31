#include <iostream>
#include <algorithm>
using namespace std;
int initial(int arr[],int n,int visited[])
{
	for(int i=0;i<=n;i++)
	{
		arr[i] = i;
		visited[i] = 0;
	}
}
void join(int arr[],int x,int y,int n)
{
	int temp = arr[x];
	for(int i=1;i<=n;i++)
	{
		if(arr[i] == temp)
			arr[i] = arr[y];
	}
}
int main()
{
	int n,k,x,y;
	long long int ans=1,count = 0;
	cin>>n;
	int arr[n+1],e[n+1],visited[n+1];
	initial(arr,n,visited);
	for(int i=1;i<=n;i++)
		cin>>e[i];
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int x,y;
		cin>>x>>y;
		join(arr,x,y,n);
	}
	for(int i=1;i<=n;i++)
	{
		if(visited[arr[i]] == 0)
		{
			visited[arr[i]] = 1;
			int temp = arr[i];
			x = 99999;
			for(int j=1;j<=n;j++)
			{
				if(arr[j] == temp)
					x = min(x,e[j]);
			}
			//cout<<x<<" l"<<"\n";
			count = 0;
			for(int j=1;j<=n;j++)
			{
				if(arr[j] == temp && e[j] == x)
					count++;
			}
			//cout<<endl<<temp<<" x:"<<x<<" count of x:"<<count<<endl;
			ans = ans*count;
			ans%=1000000007;
		}
	}
	cout<<ans;
}