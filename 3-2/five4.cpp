#include <stdio.h>
int arr[1000];
int main()
{
	int n,i;scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int j,temp,pindex = 0; 
	for(i=0;i<10;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[j]%10 == i)
			{
				temp = arr[pindex];
				arr[pindex] = arr[j];
				arr[j] = temp;
				pindex++;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}