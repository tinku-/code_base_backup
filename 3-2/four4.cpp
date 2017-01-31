#include <stdio.h>
void merge(int arr[],int n,int left[],int l,int right[],int r)
{
	int i=0,j=0,k=0;
	while(i<l && j<r)
	{
		if(left[i] <= right[j])
		{
			arr[k] = left[i];
			k++;i++;
		}
		else
		{
			arr[k] = right[j];
			k++;j++;
		}
	}
	while(i<l)
	{
		arr[k] = left[i];
		k++;i++;
	}
	while(j<r)
	{
		arr[k] = right[j];
		k++;j++;
	}
}
void mergesort(int arr[],int n)
{
	if(n>1)
	{
		int mid = n/2,i;
		int left[10000];
		int right[10000];
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
	int n,i,count = 1,max1 = -1,max2 =-1,temp1,temp2;
	scanf("%d",&n);
	int arr[10000];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	mergesort(arr,n);	
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	for(i=0;i<n-1;i++)
	{
		if(arr[i] == arr[i+1])
		{
			count++;
		}
		else
		{
			if(count > max1)
			{
				temp1 = arr[i];
				max1 = count;
				count = 1;
			}
			count = 1;
		}
	}
	count = 1;
	for(i=n-1;i>0;i--)
	{
		if(arr[i] == arr[i-1])
		{
			count++;
		}
		else
		{
			if(count > max2)
			{
				temp2 = arr[i];
				max2 = count;
				count = 1;
			}
			count = 1;
		}
	}
	if(max1 == max2 && temp1 != temp2)
		printf("\ntie\n");
	else
		printf("\n%d\n",temp1);
	return 0;
}