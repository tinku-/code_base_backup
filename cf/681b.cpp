#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	long long int a,b,c,x,y,z;
	x = 1234567;y = 123456;z = 1234;
	long long int sum,sum2;
	long long int m = 1000000000;
	for(int i=0;n>=(i*x);i++)
	{
		for(int j=0;n>=(i*x+j*y);j++)
		{
			if((n-i*x-j*y)>= 0 && (n-i*x-j*y)%z == 0)
			{
				cout<<"YES";
				return 0;
			}
		}
	}
	cout<<"NO";
	return 0;
}