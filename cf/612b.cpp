#include <iostream>
using namespace std;
long long int abs(long long int a,long long b)
{
	if(a>b)
		return (a-b);
	return (b-a);
}
int main()
{
	long long int n,sum = 0;
	cin>>n;
	long long int arr[n+1];
	for(int i=1;i<=n;i++)
	{
		long long int t;
		cin>>t;
		arr[t] = i;
	}
	for(int i=1;i<n;i++)
	{
	//	cout<<arr[i]<<" ";
		sum = sum + abs(arr[i+1],arr[i]);
	}
	cout<<sum;
	return 0;
}