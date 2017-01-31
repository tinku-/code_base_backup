#include <stdio.h>
int arr[10001];
int count =0;
int first(int x,int n)
{

	int low = 0,high = n-1;
	while(high >= low)
	{
		count++;
		int mid = (high + low)/2;
		if(( mid == 0 || x > arr[mid-1]) && arr[mid] == x)
			return mid;
		if(arr[mid] < x)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}
int last(int x,int n)
{
	int low = 0,high = n-1;
	while(high >= low)
	{
		count++;
		int mid = (high + low)/2;
		if(( mid == n-1 || x < arr[mid+1]) && arr[mid] == x)
			return mid;
		if(arr[mid] > x)
			high = mid - 1;
		else
			low = mid + 1;							
	}
	return -1;
}
int main()
{
	int n,i,x;
	scanf("%d",&n);
	scanf("%d",&x);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("%d\n",last(x,n)-first(x,n)+1);
	printf("\n%d\n",count);
	return 0;
}