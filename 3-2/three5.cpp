#include <stdio.h>
int n;
int arr[101][101] = {0};
int mx(int a,int b)
{
	if(a>=b)
		return a;
	return b;
}
void input()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
}
int fun(int m)
{
	//printf("m:%d\n",m);
	int sum=0,ans=-1001;
	int i=0,j=0,k=0,l=0;
	for(i=0;i<n-m+1;i++)
		for(j=0;j<n-m+1;j++)
		{
			sum = 0;
			for(k=0;k<m;k++)
				for(l=0;l<m;l++)
				{
					sum += arr[i+k][j+l];
				}
			ans = mx(sum,ans);
			//printf("%d: %d\n",m,ans);
		}	
	return ans;
}
int main()
{
	int x = -1001,i=0;
	input();
	for(i=1;i<=n;i++)
		x = mx(x,fun(i));
	printf("%d\n",x);
	return 0;
}
//done..........