#include <iostream>
using namespace std;
int first(int arr[],int start,int end,int x)
{
	while(start <= end)
	{
		int mid = (start + end)/2;
		if((arr[mid] == x && arr[mid-1] < x) || (arr[mid] == x && mid == start))
			return mid;
		else if(arr[mid] >= x)
			end = mid - 1;
		else
			start = mid + 1;
	}
}
int last(int arr[],int start,int end,int x)
{
	while(start <= end)
	{
		int mid = (start + end)/2;
		if((arr[mid] == x && arr[mid+1] > x) || (arr[mid] == x && mid == end))
			return mid;
		else if(arr[mid] <= x)
			start = mid + 1;
		else
			end = mid - 1;
	}
}
int main()
{
	int n,x;cin>>n>>x;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<last(arr,0,n-1,x)-first(arr,0,n-1,x)+1<<endl;
	return 0;
}
