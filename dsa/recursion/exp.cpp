//exponentation 
#include <bits/stdc++.h>
using namespace std;
long long int exp(int x,int n)
{
	long long int y;
	if(n == 0)
		return 1;
	if(n%2 == 0)
	{
		y = exp(x,n/2);
		return y*y;
	}
	else 
		return x*exp(x,n-1);
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<exp(a,b);
	return 0;
}