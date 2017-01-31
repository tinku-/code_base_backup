#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n=0;
	cin>>n;
	long long int d = __gcd(1234567,__gcd(1234,123456));
	cout<<d;
	if(n%d == 0)
		cout<<"YES";
	else
		cout<<"NO";
}