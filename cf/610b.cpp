#include <iostream>
using namespace std;
long long int max(long long int a,long long int b)
{
	if(a >= b)
		return a;
	return b;
}
int main()
{
	long long int end,temp=0,start=-1,n,t,M = 1000000000,mx=0;
	cin>>n;
	long long int arr[n],brr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		brr[i]=0;
		if(M >= arr[i])
		{
			end = i;
			M = arr[i];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i] == M)
		{
			if(start == -1)
				start = i;
			brr[i] = 1;
		}
	}
	mx = max((start + n - end - 1),mx);
	temp = start;
	for(int i=start;i<=end;i++)
	{
		if(arr[i] == M)
		{
			mx = max(mx,i - temp - 1);
			temp = i;
		}
	}
	//cout<<M<<" "<<mx<<" ";
	cout<<(mx + M*n);
	return 0;
}