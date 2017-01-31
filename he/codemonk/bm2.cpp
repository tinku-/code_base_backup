#include <bits/stdc++.h>
using namespace std;
int counter(long long int n)
{
	int i=0;
	while(n)
	{
		n = n&(n-1);
		i++;
	}
	return i;
}
int main()
{
	long long int n,M,P;cin>>n;
	while(n--)
	{
		cin>>M>>P;xx
		if(M == P)
			cout<<0<<endl;
		else
			cout<<counter(M^P)<<endl;
	}
}