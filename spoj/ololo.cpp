#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,temp,ans=0;
	cin>>n;
	while(n--)
	{
		scanf("%lld",&temp);
		ans = ans^temp;
	}
	cout<<ans;
}