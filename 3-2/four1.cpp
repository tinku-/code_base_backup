#include <stdio.h>	
#include <stdlib.h>
struct rankers
{
	char name[100];
	int rank;
};
void merge(struct rankers arr[],int n,struct rankers left[],int l,struct rankers right[],int r)
{
	int i=0,j=0,k=0;
	while(i<l && j<r)
	{
		if(left[i].rank <= right[j].rank)
		{
			arr[k] = left[i];
			i++;k++;
		}
		else
		{
			arr[k] = right[j];
			j++;k++;
		}
	}
	while(i<l)
	{
		arr[k] = left[i];
		i++;k++;
	}
	while(j<r)
	{
		arr[k] = right[j];
		j++;k++;
	}
}
void mergesort(struct rankers arr[],int n)
{
	if(n>1)
	{
		int mid = n/2,i;
		struct rankers left[1000];
		struct rankers right[1000];
		for(i=0;i<mid;i++)
			left[i] = arr[i];
		for(i=mid;i<n;i++)
			right[i-mid] = arr[i];
		mergesort(left,mid);
		mergesort(right,n-mid);
		merge(arr,n,left,mid,right,n-mid);
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
		fgets(arr[i].name,100,stdin);
	}
	mergesort(arr,n);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i].rank);
		printf("%s",arr[i].name);
	}
}

