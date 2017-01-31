#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,ans=0;
		cin>>n;
		int f,p;
		int arr[1000006];
		for(int i=0;i<1000006;i++)
			arr[i] = 0;
		for(int i=0;i<n;i++)
		{
			cin>>f>>p;
			if(f != p)
			{
				if(arr[p] > 0)
					arr[p]--;
				else
					ans++;
				arr[f]++;
			}
		}
		cout<<ans<<endl;
	}
}