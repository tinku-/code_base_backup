#include <stdio.h>
#include <stdlib.h>
int print(int k)
{
	if(k<=9)
		printf("0%d ",k);
	else
		printf("%d ",k);
}
int main()
{
	int n,i,j,k=1;
	scanf("%d",&n);
	int *arr= (int *)malloc(n*n*sizeof(int));
	int t=0,l=0,b=n-1,r=n-1,dir=0;
	i=0,k=1;
	while(t <= b && l <= r)
	{
		//first row 
		if(dir == 0)
		{
			for(i=l;i<=r;i++)
			{
				*(arr + t*n + i) = k;
				k++;
			}
			t++;
			dir = 1;
		}
		if(dir == 1)
		{
			for(i=t;i<=b;i++)
			{
				*(arr + i*n + r) = k;
				k++;
			}
			r--;
			dir = 2;
		}
		if(dir == 2)
		{
			for(i=r;i>=l;i--)
			{
				*(arr + b*n + i) = k;
				k++;
			}
			b--;
			dir = 3;
		}
		if(dir == 3)
		{
			for(i=b;i>=t;i--)
			{
				*(arr + i*n + l) = k;
				k++;
			}
			l++;
			dir = 0;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			print(*(arr + i*n + j));
		}
	}
	return 0;
}