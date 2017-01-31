#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int check(double a)
{
	int f=0;
	long long int i=2;
	while(i<=pow(a,0.5))
	{
		if(a%i==0){f=1;return f;}
		i++;
	}
	return f;
}
int main()
{
	double n,prime=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		if(check(i)==0){if(n%i==0)prime=i;}
	}
	cout<<"\n"<<prime<<"\n";
	
	return 0;
}
