#include <iostream>
#include <algorithm>
using namespace std;
int binarysearch(int arr[],int start,int end,int x)
{
	while(start <= end)
	{
		int mid = (start + end)/2;
		if(arr[mid] == x)
			return mid;
		else if(arr[mid] > x)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}
int main()
{
	int n,q;cin>>n>>q;
	int arr[n];
	for(int i=n-1;i>=0;i--)
		cin>>arr[i];
	sort(arr,arr+n);
	for(int i=0;i<q;i++)
	{
		int x;cin>>x;
		if(binarysearch(arr,0,n-1,x) == -1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}