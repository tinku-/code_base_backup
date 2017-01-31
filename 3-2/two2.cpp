#include <stdio.h>
int checker(long long int x)
{
	long long int rev =0;
	int cd = x%10,sum=0,i=0;
	x = x/10;
	while(x)
	{
		if(i%2 == 0)
			sum += ((x%10)*2)%10 + ((x%10)*2)/10;
		else
			sum += x%10;

		x = x/10;
		i++;
	}
	sum += cd;
	printf("\n%d\n",sum);
	if(sum%10 == 0)
		return 1;
	return 0;
}
int main()
{
	long long int n;
	scanf("%lld",&n);
	if(checker(n) == 1)
	{
		printf("valid");
		return 0;
	}
	printf("invalid");
	return 0;
}