#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,sum = 0,temp = 0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum += arr[i];
	}
	sum /= (n/2);
	int card=0,i=0;
	while(card != n/2)
	{
		temp = arr[i];
		if(arr[i] != 0)
		{
			for(int j=i+1;j<n;j++)
			{
				if(temp + arr[j] == sum)
				{
					cout<<i+1<<" "<<j+1<<endl;
					arr[j] = 0;
					card++;
					break;
				}
			}
		}
		arr[i] = 0;
		i++;

	}
}