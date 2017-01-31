#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int brr[n][m],arr[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>arr[i][j];

	int l = 0,r = m-1,t = 0,d = n-1;
	while(l < r && t < d)
	{
		for(int i=l;i<=r;i++)
		{
			//cout<<"yo1"<<endl; 
			cout<<arr[t][i]<<" ";
		}t++;
		for(int i=t;i<=d;i++)
		{
			//cout<<"yo2"<<endl;
			cout<<arr[i][r]<<" ";
		}r--;
		if(t < d)
		{
			for(int i=r;i>=l;i--)
			{
				//cout<<"yo3"<<endl;
				cout<<arr[d][i]<<" ";
			}d--;
		}
		if(l < r)
		{
			for(int i=d;i>=t;i--)
			{
				//cout<<"yo4"<<endl;
				cout<<arr[i][l]<<" ";
			}l++;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<brr[i][j]<<" ";
		}
		cout<<endl;
	}
}