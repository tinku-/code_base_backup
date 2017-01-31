#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	for(int i=1;i<=t;i++)
	{
		
		int sum,n;
		cin>>sum>>n;
		int arr[n];
		for(int j=0;j<n;j++)
			cin>>arr[j];
		sort(arr,arr+n);
		int ans = 0,curr_sum=0,flag = 0;
		cout<<"Scenario #"<<i<<":"<<endl;
		for(int j=n-1;j>=0;j--)
		{
			curr_sum += arr[j];
			ans++;
			if(curr_sum >= sum)
			{
				cout<<j<<endl;
				flag = 1;
				break;
			}	
			
		}
		if(flag == 0)
			cout<<"impossible"<<endl;
	}return 0;
}