#include <stdio.h>
int brr[1000000] = {0};
int merge(int arr[],int n,int left[],int l,int right[],int r)
{
	int count=0,counter=0;
	int i=0,j=0,k=0;
	while(i<l && j<r)
	{
		if(left[i] > right[j])
		{
			arr[k] = right[j];
			j++;k++;
			count++;
		}
		else
		{
			brr[left[i]] += count;
			counter += count;
			arr[k] = left[i];
			i++;k++;
			
		}
	}
	while(i<l)
	{
		brr[left[i]] += count;
		counter += count;
		arr[k] = left[i];
		i++;k++;
	}
	while(j<r)
	{
		arr[k] = right[j];
		j++;k++;
	}
	return counter;
}
int mergesort(int arr[],int n)
{
	int ans = 0;
	if(n > 1)
	{
		int mid = n/2,i;
		int left[10000];
		int right[10000];
		for(i=0;i<mid;i++)
			left[i] = arr[i];
		for(i=mid;i<n;i++)
			right[i-mid] = arr[i];
		ans = mergesort(left,mid);
		ans += mergesort(right,n-mid);
		ans += merge(arr,n,left,mid,right,n-mid);
	}
	return ans;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[10000],crr[100000];
	for(i=0;i<n;i++)
		{scanf("%d",&arr[i]);crr[i] = arr[i];}
	int ans = mergesort(arr,n);
	printf("%d\n",ans);
	for(i=0;i<n;i++)
		printf("%d ",brr[crr[i]]);
	printf("\n");
	return 0;
}

//this algoridam passes all test cases form quesion
// https://www.hackerearth.com/code-monk-sorting/algorithm/puchi-and-luggage/