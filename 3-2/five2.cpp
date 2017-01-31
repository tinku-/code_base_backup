#include <stdio.h>
//used similar inplace partition function as quicksort.
int partitionOddEven(int arr[],int start,int end)
{
	int i=0,index=0,temp;
	for(i=start;i<end;i++)
	{
		if(arr[i]%2 == 0)
		{
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;
		}
	}
}
int main()
{
	int n,i;
	int arr[100000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	partitionOddEven(arr,0,n);
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
//input n
//then input arr[n]
/*
input
8
7 17 74 21 7 9 26 10
output
74 26 10 21 7 9 17 7 
*/