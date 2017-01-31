#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int t;
	long long int n,x;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lld",&n);
		x=(long long int)(sqrt(n+1));
		if(x*x==n)
			printf("Case %d: Yes\n",i);
		else
			printf("Case %d: No\n",i);
	}
	return 0;
}