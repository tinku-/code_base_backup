#include <stdio.h>
int v,sum=0;
int i=0;	
int deg[3001];
int fokat[200];
int main()
{
	scanf("%d",&v);
	for(i=0;i<v;i++)
	{
		scanf("%d",&deg[i]);
		sum+=deg[i];
		fokat[i]++;
	}
	if(sum%2==1)
	{
		printf("invalid"); 
		return 0;
	}
	else 
	{
		if(sum == v*(v-1))
		{
			printf("complete"); 
			return 0;
		}
		if(sum == 2*(v-1))
		{
			printf("star"); 
			return 0;
		}
		if(sum == 2*v)
		{
			printf("cycle"); 
			return 0;
		}
		if(sum == (v-1)*4)
		{
			printf("wheel"); 
			return 0;
		}
		else
			printf("none");
	}
	return 0;
}