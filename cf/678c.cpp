#include <bits/stdc++.h>
using namespace std;
long long int min2(long long int x,long long int y)
{
	if (x > y)
		return y;
	return x;
}
int main()
{
	long long int n,a,b,p,q;
	long long int ans = 0;
	cin>>n>>a>>b>>p>>q;
	ans = (n/a)*p + (n/b)*q - (n/((a*b)/__gcd(a,b)))*min2(p,q);
	cout<<ans;
}