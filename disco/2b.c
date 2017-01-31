#include <stdio.h>
int adj[201][201];
int sort[201];
int v1,v2,v,e,sum,i,j,k,r,d;
int main()
{
	for(i=0;i<201;i++)
		sort[i]=0;
	for(i=0;i<201;i++)
		for(j=0;j<201;j++)
			adj[i][j]=0;

	scanf("%d %d",&v,&e);
	for(i=0;i<e;i++)
	{
		scanf("%d %d",&v1,&v2);
		adj[v1][v2]=1;
		adj[v2][v1]=1;
	}
    for(k=0;k<v;k++)
    { 
      	for(j=0;j<v;j++)
      	{ 
            for(k=0;k<v;k++)
               {
               		if(adj[i][j]>(adj[i][k]+adj[k][j]))
               			adj[i][j]=adj[i][k]+adj[k][j];
               }
        }
    }
    for(i=0;i<v;i++)
    {
    	for(j=0;j<v;j++)
    		printf("%d ",adj[i][j]);
    	printf("\n");
    }	

    for(i=0;i<v;i++)
    	for(j=0;j<v;j++)
    		{
    			if(adj[i][j]!=0)
					sort[adj[i][j]]=1;
    		}
    for(i=1;i<201;i++)
    {
    	if(sort[i]==1)
    	{
    		r=i;
    		break;
    	}
    }
    for(i=200;i>0;i--)
    {
    	if(sort[i]==1)
    	{
    		d=i;
    		break;
    	}
    }
    printf("%d %d",r,d);
    return 0;

}