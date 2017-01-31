#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n; //no of elements in array
	int arr[n]; 
	for(int i=0;i<n;i++)
		cin>>arr[i]; //elements in array
	int sum=0,ans=0;
	//kdanes algorithm
	for(int i=0;i<n;i++)
	{
		sum += arr[i];
		if(sum > ans)
			ans = sum;
		else if(sum < 0)
			sum = 0;
	}
	cout<<ans<<endl;
}