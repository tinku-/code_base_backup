#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(n == 0)return 0;
		double ans = (n*n)/(2*M_PI);
		cout<<setprecision(2)<<fixed<<ans<<endl;
	}
}