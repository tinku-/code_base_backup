#include <cstdio>
using namespace std;
int main()
{
	unsigned long long int two[51],four[51],six[51];
	two[0]=0;
	two[1]=1;
	four[0]=0;
	four[1]=1;
	six[0]=0;
	six[1]=1;
	for(int i=2;i<=50;i++)
	{
		two[i]=two[i-1]+four[i-1];
		four[i]=two[i-1]+four[i-1]+six[i-1];
		six[i]=four[i-1]+six[i-1];
	}
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%lld\n",two[n]+four[n]+six[n]);
	}
	return 0;
}