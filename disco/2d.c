#include <stdio.h>
int t=0;
int adj[201][201];
int deg[201];
int v1,v2,v,e,i,j,k,count,temp;
int ridam()
{
	count=0;
	for(i=1;i<=v;i++)
		for(j=1;j<=v;j++)
			deg[i]=deg[i]+adj[i][j];
	for(i=1;i<=v;i++)
	{
		if(deg[i]%2==0)
			count++;
	}
	if(count==v)
		{printf("Eulerian circuit\n");return 0;}
	else if((v-count)==2)
		{printf("Eulerian path\n");return 0;}

	printf("neither\n");
	return 0;

}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<201;i++)
		{
			deg[i]=0;
			for(j=0;j<201;j++)
				adj[i][j]=0;
		}
		scanf("%d %d",&v,&e);
		for(i=0;i<e;i++)
		{
			scanf("%d %d",&v1,&v2);
			adj[v1][v2]=1;
			adj[v2][v1]=1;
		}
		ridam();

	}
}