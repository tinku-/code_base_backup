#include <stdio.h>
int main()
{
	long long int ans=0;
	long long int a;
	scanf("%lld",&a);
	while(a)
	{
		if(a%2 ==1)
			ans++;
		a = a/2;
	}
	printf("%lld\n",ans);
}