#include <cstdio>
using namespace std;
int main()
{
	int n,d,A[1000000]={0,0};
	for(int i=1;i<1000000;i++)
	{
		if(A[i]==0)
		{
			printf("%d\n",i);
			n=i;
			while(n<1000000)
			{
				if(A[n]==0)
				{
					A[n]=1;
					d=n;
				}
				else
					break;
				while(d!=0)
				{
					n+=(d%10);
					d/=10;
				}
			}
		}
	}
	return 0;
}