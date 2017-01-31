#include <iostream>
using namespace std;
int main()
{
	long long int sum,ans=0,arr[1000000],n,k;
	cin>>n>>k;arr[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		arr[i] = arr[i] + arr[i-1];
	}
	for(int i=0;i<=n-k;i++)
	{
		//cout<<(arr[i+k]  - arr[i])<<endl;
		if(arr[ans+k] - arr[ans] > arr[i+k]  - arr[i ])
			ans = i;
	}
	cout<<ans+1;
}