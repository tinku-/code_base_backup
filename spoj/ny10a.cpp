#include <bits/stdc++.h>
using namespace std;
#define MAXZISE 100000;
int fun(int a,int b,int c)
{
	int ans = 2*2*a + 2*b + c;
	return ans;
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		char c;
		int k;cin>>k;
		int arr[8],ans[40];
		for(int i=0;i<40;i++)
		{
			cin>>c;
			arr[i%8] = 0;
			if(c == 'H')
				ans[i] = 1;
			else
				ans[i] = 0;
		}
		for(int i=0;i<38;i++)
			arr[fun(ans[i],ans[i+1],ans[i+2])]++;
		cout<<k<<" ";
		for(int i=0;i<8;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	return 0;
}
