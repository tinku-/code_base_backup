#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		long long int x,y,z;
		cin>>x>>y>>z;
		long long int n = (2 * z)/(x + y),d,a;
		cout<<n<<endl;
		d = (y - x)/(n-5);
		a = x - 2 * d;
		//cout<<a<<" "<<d<<" "<<n<<endl;

		while(n--)
		{
			cout<<a<<" ";
			a += d;
		}cout<<endl;
 	}
}