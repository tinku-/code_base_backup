#include <stdio.h>
int arr[1000];
int brr[1000];
int heapsize = 0;
int formheap(int x)
{
	heapsize++;
	arr[heapsize] = x;
	int n = heapsize;
	while(arr[n/2] < x)
	{
		arr[n] = arr[n/2];
		n = n/2;
	}
	arr[n] = x;
}
int heapify()
{
	int i=1,next; 

	int temp;
	if(arr[heapsize] < arr[1])
	{
		//swap
		temp = arr[heapsize];
		arr[heapsize] = arr[i];
		arr[i] = temp;
	}

	heapsize--;
	for(i=1;2*i<heapsize;i=next)
	{
		next = 2*i;
		if(arr[next] < arr[next+1])
			next++;
		if(arr[next] > arr[i])
		{
			//swap
			temp = arr[next];
			arr[next] = arr[i];
			arr[i] = temp;
		}
		else
			break;
	}
}
int main()
{
	int x,i,n,j;
	scanf("%d",&n);
	arr[0] = 999999;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		formheap(x);
	}
	//heap sort...
	for(i=n;i>0;i--)
	{
		heapify();
	}
	for(j=1;j<=n;j++)
			printf("%d ",arr[j]);
		printf("\n");
	
}