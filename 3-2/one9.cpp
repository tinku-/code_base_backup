#include <stdio.h>
int a[1000][1000];
int b[1000][1000];
int arr[1000][1000];
int multi(int m,int p,int n)
{
	int i=0,j=0,k=0,sum=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			arr[i][j]=0;
			for(k=0;k<p;k++)
			{
				arr[i][j] = arr[i][j] + a[i][k]*b[k][j];
			}
		}
	}
	sum = 0;
	for(i=0;i<m;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
			sum = sum + arr[i][j];
		}
	}
	return sum;
}
int main()
{
	int m,n,p,i,j;
	scanf("%d %d",&m,&p);
	for(i=0;i<m;i++)
	{
		for(j=0;j<p;		j++)
			{scanf("%d",&a[i][j]);}
	}
	scanf("%d %d",&p,&n);
	for(i=0;i<p;i++)
	{
		for(j=0;j<n;j++)
			{scanf("%d",&b[i][j]);}
	}
	printf("\n\n%d\n",multi(m,p,n));
	return 0;
}

//done/.......................