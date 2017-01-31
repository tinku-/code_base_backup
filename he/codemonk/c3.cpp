#include <iostream>
#include <algorithm>
using namespace std;
long long int binarysearch(long long int arr[],long long int start,long long int end,long long int x)
{
	while(start <= end)
	{
		long long int mid = (start + end)/2;
		if((arr[mid] <= x && arr[mid-1] > x) || (arr[mid] <= x && mid == 0))
			return mid;
		else if(arr[mid] <= x)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return 1000000;
}
int main()
{
	long long int t;cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		long long int arr[n],brr[n];
		for(long long int i=0;i<n;i++)
			cin>>arr[i];
		for(long long int i=0;i<n;i++)
			cin>>brr[i];
		long long int ans = 0;
		for(long long int j=n-1;j>=0;j--)
		{
			//cout<<" searching:"<<j<<" "<<binarysearch(arr,0,j,brr[j])<<endl;
			ans = max(j-binarysearch(arr,0,j,brr[j]),ans);
		}
		cout<<ans<<endl;
	}
}