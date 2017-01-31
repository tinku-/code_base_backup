#include <cstdio>
using namespace std;
int main()
{
	int t,n;
	int A[1001];
	A[0]=0;
	for(int i=1;i<=1000;i++)
	{
		t=i;
		n=0;
		while(t!=0)
		{
			if(t%2==1)
				n++;
			t/=2;
		}
		A[i]=A[i-1]+n;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",A[n]);
	}
	return 0;
}