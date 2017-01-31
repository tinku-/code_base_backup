#include <stdio.h>
#include <math.h>
int arr[20] = {0};
int fun(long long int seed)
{
	int	temp = seed;
	int t=0;
	while(temp)
	{
		temp = temp/10;
		t++;
	}
	long long int square = seed*seed;
	temp = square;
	int s = 0;
	while(temp)
	{
		temp = temp/10;
		s++;
	}
	if((s-t)%2==0)
	{
		long long int l = pow(10,(s-t)/2);
		long long int m = pow(10,t);
		seed = (square/l)%m;
		return seed;
	}
	else
	{
		long long int l = pow(10,(s-t)/2+1);
		long long int m = pow(10,t);
		seed = (square/l)%m;
		return seed;
	}
}
int main()
{
	long long int seed,n,temp;
	scanf("%lld",&seed);
	scanf("%lld",&n);
	while(n--)
	{
		seed = fun(seed);		
		printf("%lld\n",seed);
	}
	
	return 0;
}