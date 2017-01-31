#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
	int n,p;
	cin>>n>>p;
	int arr[n];
	for(int i=n-1;i>=0;i--)
	{
		char s[100];
		cin>>s;
		if(strcmp(s,"half") == 0)
			arr[i] = 0;
		else
			arr[i] = 1;
	}
	long long int ans = p/2;
	double apples = 1;
	for(int i=1;i<n;i++)
	{	
		apples = (apples*2) + (arr[i]*2)/2; //cout<<arr[i]<<" "<<apples<<endl;
		ans += apples/2*p;
	}
	cout<<ans;
	return 0;
}