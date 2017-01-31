#include <stdio.h>
struct rankers
{
	char name[100];
	int rank;
};
void insertionsort(struct rankers arr[],int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		int j=i;
		struct rankers temp = arr[j];
		while(arr[j-1].name > temp.name && j > 0)
		{
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = temp;
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	struct rankers arr[10000];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i].rank);
		scanf("%s",arr[i].name);
	}
	insertionsort(arr,n);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i].rank);
		printf("%s\n",arr[i].name);
	}
}