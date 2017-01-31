#include <iostream>
#define MAXSIZE 100000;

using namespace std;

int main()
{
	long long int n,m,ans=0,temp;
	long long int arr[12]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		arr[temp]++;
	}
	for(int i=1;i<11;i++)
	{
		ans = ans + arr[i]*(n-arr[i]);
	}
	cout<<ans/2;
}