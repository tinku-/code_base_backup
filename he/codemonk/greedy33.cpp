#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		int arr[n];
		long long int crr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			if(arr[i] != 0 && i>0)
				crr[i] *= arr[i]*arr[i-1];
		}
	}
}