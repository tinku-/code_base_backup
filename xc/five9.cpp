#include <stdio.h>
int continuous1s(int arr[],int n)
{
	int start = -1,end,mid = -1,ans = -1,count = -1;
	for(end=0;end<n;end++)
	{
		if(arr[end] == 0)
		{
			if(end - start > count)
			{
				ans = mid;
				count = end - start;	
			}
			start = mid;
			mid = end;
		}
	}
	if(n - start > count)
		ans = mid;
	return mid;
}
int main()
{
	int n,i;
	int arr[100000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\n%d\n",continuous1s(arr,n));
	return 0;
}