#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j,k,t,n,m,p1,p2,ec=1,cnt=0, a[50][50],ds[50];
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		for(i=0;i<50;i++)
		{
			ds[i]=0;
			for(j=0;j<50;j++)
				a[i][j]=0;
		}
		scanf("%d %d",&n,&m);
		for(j=0;j<m;j++)
		{
			scanf("%d %d",&p1,&p2);
			a[p1-1][p2-1]=1;
			a[p2-1][p1-1]=1;
		}
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
				ds[j]=ds[j]+a[j][k];
		}
		for(j=0;j<n;j++)
		{
			if(ds[j]%2==0)
				cnt++;
		}
		if(cnt==n)
		{
			printf("Eulerian circuit\n");
		}
		else if((n-cnt)==2)
		{
			printf("Eulerian path\n");
		}
		else
			printf("neither\n");
	}
	return 0;
}
