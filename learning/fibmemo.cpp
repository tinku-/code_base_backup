//recursive fibonacci with memoization
#include <iostream>
using namespace std;
int f[51];
int fib(long long int n)
{
	if(f[n]!=-1)
		{
			return f[n];
		}
	f[n]=(fib(n-1)+fib(n-2));
	return f[n];
}

//driver function
int main()
{
	for(int i=0;i<51;i++)
	{
		f[i]=-1;
	}
	f[0]=0;f[1]=1;	
	long long int a;
	cin>>a;
	cout<<fib(a);
r	eturn 0;
}