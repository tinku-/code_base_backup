#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,temp,flag = 0;cin>>n;
	int arr[n];
	int brr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		brr[i] = arr[i];
	}
	sort(brr,brr+n);
	int top = n-1;
	for(int i=0;i<n;i++)
	{
		flag = 0;
		for(int j=0;j<=top;j++)
		{
			if(arr[j] == brr[top] && j != top)
			{
				flag = 1;
				x = j;
				break;
			}
		}
		if(flag == 1)
		{
			while(x != top)
			{	
				cout<<x+1<<" "<<x+2<<endl;
				temp = arr[x];
				arr[x] = arr[x+1];
				arr[x+1] = temp;
				x++;
			}
		}
		top--;
	}

}