#include <bits/stdc++.h>
using namespace std;
int heapsize = 0;
void max_heapify(int arr[],int n,int i)
{
	int left = 2*i;
	int right = 2*i+1;
	int largest;
	if(left <= n && arr[left] > arr[i])
		largest = left;
	else
		largest = i;
	if(right <= n && arr[right] > arr[i])
		largest = right;
	if(largest != i)
	{
		swap(arr[i],arr[largest]);
		max_heapify(arr,n,largest);
	}
}
int heapify_up(int arr[],int i)
{
	int x = arr[i];
	while(i > 1 && arr[i/2] < arr[i])
	{
		swap(arr[i],arr[i/2]);
		i = i/2;
	}
}
void print(int arr[],int i)
{
	long long int ans = 0;
	if(i > 2)
		ans = arr[1]*arr[2]*arr[3];	
	else
		ans = -1;
	cout<<ans<<endl;
}
int main()
{
	int n;cin>>n;
	int arr[n+1];
	arr[0] = 9999999;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	for(int i=0;i<=	n;i++)
	{
		heapify_up(arr,i);
		for(int i=1;i<=n;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		//print(arr,i);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}