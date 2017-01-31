#include <iostream>
using namespace std;
int arr[100][100] = {-1};
int brr[100] = {-1};
int main()
{
	int n;
	cin>>n;
	int crr[n];
	for(int i=0;i<n;i++)
		crr[i] = i+1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	for(int j=0;j<n;j++)
		{
			for(int i=0;i<n;i++)	
			{
				brr[j] = max(brr[j],arr[i][j]);
			}
		}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(brr[i] == brr[j] && i != j)
				brr[i]++;
		}
	}
	for(int i=0;i<n;i++)
		cout<<brr[i]<<" ";


}	