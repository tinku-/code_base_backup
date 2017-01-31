#include <cstdio>
using namespace std;
int A[1001],B[1001]={0,0};
int f(int x)
{
	if(B[x]==1)
		return 1;
	else
		return 10000;
}
int main()
{
	int t,ar;
	for(int i=1;i*i<=1000;i++)
		B[i*i]=1;
	for(int i=1;i<=1000;i++)
	{
		A[i]=f(i);
		for(int j=1;j<=i/2;j++)
		{
			t=A[j]+A[i-j];
			if(t<A[i])
				A[i]=t;
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&ar);
		printf("%d\n",A[ar]);
	}
	return 0;
}