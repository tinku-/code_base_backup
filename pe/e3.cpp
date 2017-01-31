#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int check(long long int a)
{
	int f=0;
	long long int i=2;
	while(i<pow(a,0.5))
	{
		if(a%i==0){f=1;return f;}
		i++;
	}	
	return f;
}
int main()
{
	long long int n,prime=0;
	cin>>n;
	for(long long int i=1;i<=n;i++)
	{
		if(check(i)==0){if(n%i==0){{prime=i;n=n/i;};cout<<"\n"<<prime<<"\n";}}
		cout<<"\n"<<prime<<"\n";
	
	}
	cout<<"\n"<<prime<<"\n";
	
	return 0;
}
