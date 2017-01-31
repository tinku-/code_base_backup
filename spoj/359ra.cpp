#include <bits/stdc++.h>
using namespace std;
int main()
{
	char c;
	int n,x;
	long long int ice=0;
	int ans = 0;
	while(n--)
	{
		cin>>c>>x;
		if(c == '+')
			ice += x;
		else
		{
			if(ice >= x)
				ice -= x;
			else
				ans++;
		}
	}cout<<ice<<ans;
	return 0;
}