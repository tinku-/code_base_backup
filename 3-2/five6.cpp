#include <stdio.h>
//galat hai
struct group
{
	char name[100];
	int gp;
}arr[1000];

int partition(struct group arr[],int start,int end,int num)
{
	int pindex,i;
	for(i=start;i<=end;i++)
	{
		if(arr[i].gp <= num)
		{
			struct group temp;
			temp = arr[i];
			arr[i] = arr[pindex];
			arr[pindex] = temp;
			pindex++;
		}
	}
	return pindex;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i].gp);
		scanf("%s",arr[i].name);
	}
	int x = partition(arr,0,n-1,1);
	partition(arr,x,n-1,2);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i].gp);
		printf("%s\n",arr[i].name);
	}
}