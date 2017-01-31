#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	for(;;)
	{
		cin>>n;
		if(n != 0)
		{
			int arr[n];
			int brr[n];
			int x;
			bool flag = false;
			for(int i=0;i<n;i++)
			{
				cin>>x;
				arr[i] = x;
				brr[x-1] = i + 1;
			}
			for(int i=0;i<n;i++)
			{
				//cout<<brr[i]<<" ";
				if(arr[i] != brr[i])
				{
					flag = true;
					cout<<"not ambiguous"<<endl;
					break;
				}
			}cout<<endl;
			if(flag == false)
				cout<<"ambiguous"<<endl;
		}
		else
			return 0;
	}
}