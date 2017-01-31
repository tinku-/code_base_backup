#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int t;cin>>t;
	while(t--)
	{
		//cout<<"lkl"<<endl;
		int n,x,z=0;
		cin>>n;
		long long int temp1 = 0;
		long long int temp = 1,kmax,kmin;
		
		int arr[n];
		bool flag = false;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		sort(arr,arr+n);
		
		for(int i=0;i<n;i++)
		{
			if(arr[i] != 0)
				temp *= arr[i];
			else
				{z++;flag = true;}

		}
		if(z == n)
		{
			cout<<0<<" "<<0<<endl;
			continue;
		}
		if(z == n-1)
		{
			if(arr[0] < 0)
			{
				cout<<arr[1%n]<<" "<<arr[0]<<endl;
				continue;
			}
			if(arr[n-1] > 0)
			{
				cout<<arr[n-1]<<" "<<arr[0]<<endl;
				continue;
			}
		}
		else if(arr[0] == 0 && arr[1] > 0)
			{cout<<temp<<" "<<arr[0]<<endl;continue;}
		else if(arr[0] > 0 && arr[n-1] > 0)
			{cout<<temp<<" "<<arr[0]<<endl;continue;}


		for(int i=n-1;i>=0;i--)
		{
			if(arr[i] < 0)
			{
				temp1 =  arr[i];
				break;
			}
		}
		kmin = temp/temp1;
		kmax = temp;
		if(kmin > kmax)
			swap(kmin,kmax);
		cout<<kmax<<" "<<kmin<<endl;
	}
}