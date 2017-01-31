#include <stdio.h>

int main()

{
	int i=0,m=0,n=0,t=0,z=0;
	int a[101];
	for(i=0;i<101;i++)
		{
			a[i]=0;
		}
	for(i=0;i<100;i++){
		scanf("%d %d",&m,&n);
		a[n]=m;
	}scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&z);
		printf("%d\n",a[k]);
	}
	return 0;
}