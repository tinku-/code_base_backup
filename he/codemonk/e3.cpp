#include <iostream>
using namespace std;
int m = 1000000007;
int gcd(int arr[],int n,int x)
{
	while(x > 0)
	{
		int flag = 0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]%x != 0)
				{flag = 1;break;}
		}
		if(flag == 0)
			return x;
		x--;
	}
	return 1;
}
long long int mod(int a,int b)
{
	long long int x=1;
	long long int power = a%m;
	while(b)
	{
		if(b%2 == 1)
			x = (x*power)%m;
		power = (power*power)%m;
		b = b/2;
	}
	return x;
}
long long int algoridam(int arr[],int n,int x)
{
	long long int ans=1;
	for(int i=0;i<n;i++)
		ans = (ans%m)*(mod(arr[i],x)%m)%m;
	return ans;
}
int main()
{
	int n,x=9999;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		x = min(x,arr[i]);
	}
	//cout<<gcd(arr,n,x)<<endl;
	cout<<algoridam(arr,n,gcd(arr,n,x));
}