#include <stdio.h>
#include <string.h>
struct rankers
{
	char name[100];
	int rank;
};
int pivotization(struct rankers arr[],int start,int end)
{
	struct rankers pivot = arr[end];
	int pindex = start,i;
	for(i=start;i<end;i++)
	{
		if(strcmp(arr[i].name,pivot.name) <= 0)
		{
			struct rankers temp;
			temp = arr[pindex];
			arr[pindex] = arr[i];
			arr[i] = temp;
			pindex++;
		}
	}
	struct rankers temp;
	temp = arr[pindex];
	arr[pindex] = arr[end];
	arr[end] = temp;
	return pindex;
}
void quicksort(struct rankers arr[],int start,int end)
{
	if(start < end)
	{
		int pivot = pivotization(arr,start,end);
		quicksort(arr,start,pivot-1);
		quicksort(arr,pivot+1,end);
	}
}
int main()
{
	int n,i=0;
	scanf("%d",&n);
	struct rankers arr[10000];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i].rank);
		scanf("%s",arr[i].name);
	}
	quicksort(arr,0,n-1);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%s ",arr[i].name);
		printf("%d\n",arr[i].rank);
	}
	return 0;
}