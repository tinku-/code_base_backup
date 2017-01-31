#include <stdio.h>
int modular(int b,int n,int m)
{
	int power=0,x=0;
	x = 1;
	power = b%m;
	while(n)
	{
		if(n%2 == 1)
			x = (x*power)%m;
		power = (power*power)%m;
		n=n/2;
	}
	return x;
}
int main()
{
	int c,n,p;
	scanf("%d %d %d",&c,&n,&p);
	printf("%d\n",modular(c,n,p));
}