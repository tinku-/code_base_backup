#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#define MAX 1000000
using namespace std;
int arr[MAX];
int main()
{
	int n,ans=0;
	cin>>n;
	int s = pow(2,n+1)-2;
	for(int i=0;i<s;i++)
	{
		cin>>arr[i];
	}
	int i = s-1;
	while(i >= 0)
	{
		ans = ans + abs(arr[i]-arr[i-1]);
		arr[i/2-1] = arr[i/2-1] + max(arr[i],arr[i-1]);
		i = i - 2;
	}
	cout<<ans;
	return 0;
}