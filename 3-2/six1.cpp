#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int countsort(int arr[],int n)
{
	int i;
	int crr[100000] = {0};
	int brr[100000] = {0};
	for(i=0;i<n;i++)
		brr[arr[i]]++; 
	for(i=1;i<100000;i++)
		brr[i] += brr[i-1];
	for(i=n-1;i>=0;i--)
	{
		crr[brr[arr[i]]] = arr[i];
		brr[arr[i]]--;
	}
	for(i=0;i<n;i++)
		arr[i] = crr[i+1];
	return 0;
}
int bucketsort(int arr[],int n)
{
	int i=0,j,k=0;
	int crr[5][100] = {0};
	for(i=0;i<n;i++)
		crr[arr[i]/20][arr[i]%20]++;
	for(i=0;i<5;i++)
	{
		for(j=0;j<100;j++)
		{
			if(crr[i][j] != 0)
			{
				arr[k] = i*20 + j;
				k++;
			}
		}
	}


}
int main()
{
	int n,i;
	int arr[100000];
	clock_t end,start;float f;
	scanf("%d",&n);
	srand(3);
	for(i=0;i<n;i++)
		arr[i] = rand()%100;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	start = clock();
	countsort(arr,n);
	end = clock();
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	f = (end - start)/CLOCKS_PER_SEC;
	printf("%f\n",f);
	for(i=0;i<n;i++)
		arr[i] = rand()%100;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	start = clock();
	bucketsort(arr,n);
	end = clock();
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	f = (end - start)/CLOCKS_PER_SEC;
	printf("%f\n",f);
	return 0;
}

