#include <bits/stdc++.h>
using namespace std;
long long int c2(long long int x)
{
	return x*(x-1)/2;
}
int main()
{
	int n,m;
	cin>>n>>m;
	long long int kmax = c2(n-m+1);
	long long int kmin = m*c2(n/m);
	if(n%m != 0)
	{
		kmin = n%m*c2(n/m+1) + (m-n%m)*c2(n/m);
	}
	cout<<kmin<<" "<<kmax;
}