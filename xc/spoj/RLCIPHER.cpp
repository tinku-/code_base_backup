#include <cstdio>
using namespace std;
int main()
{
	int t,n,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x<0)
				printf("%d ",x);
			else if(x>5)
				printf("-4 ");
			else if(x==0)
				printf("-4 ");
			else if(x==1)
				printf("-3 ");
			else if(x==2)
				printf("-2 ");
			else if(x==3)
				printf("-4 ");
			else if(x==4)
				printf("-4 ");
			else
				printf("-3 ");
			
		}
		printf("\n");
	}
	return 0;
}