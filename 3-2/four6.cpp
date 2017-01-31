#include <stdio.h>
void merge(int arr[],int n,int left[],int l,int right[],int r)
{
	int i=0,j=0,k=0;
	while(i<l && j<r)
	{
		if(left[i] <= right[j])
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
void mergesort(int arr[],int n)
{
	if(n>1)
	{
		int i=0;
		int mid = n/2;
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
int binarysearch(int arr[],int start,int end,int x)
{
	while(start <= end)
	{
		int mid = start + (end - start)/2;
		if(arr[mid] == x)
			return mid;
		if(arr[mid] > x)
			end = mid - 1;
		if(arr[mid] < x)
			start = mid + 1; 
	}
	return -1;
}
int main()
{
	int n,i,x;
	scanf("%d %d",&n,&x);
	int arr[10000];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	mergesort(arr,n);
	//printf("\n");
	for(i=0;i<n;i++)
	{
		if(binarysearch(arr,i,n,x-arr[i]) != -1)
		{
			printf("%d %d\n",arr[i],arr[binarysearch(arr,i,n,x-arr[i])]);
			printf("YES\n");
			return 0;   
			//nlogn (binary search n times)+ nlogn(merge sort) = nlogn total time complexity.
		}
	}
	printf("NO\n");
	/*for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");*/
	return 0;
}