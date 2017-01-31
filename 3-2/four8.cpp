#include <stdio.h>
int length(char arr[])
{
	int i=0;
	while(arr[i] != '\n' && arr[i] != '\0')
		i++;
	return i;
}
int higest(char arr[],int n)
{
	int i,max = -1;
	for(i=0;i<n-1;i++)
	{
		if(arr[i] < arr[i+1])
			max = i;
	}
	return max;
}
int swap(char arr[],int n,int i)
{
	int j;
	char c;
	for(j=n-1;j>i;j--)
	{
		if(arr[j] > arr[i])
		{
			c = arr[i];
			arr[i] = arr[j];
			arr[j] = c;
			return 0;
		}
	}
	return -1;
}
void reverse(char arr[],int start,int end)
{
	char c;
	while(start < end)
	{
		c = arr[start];
		arr[start] = arr[end];
		arr[end] = c;
		start++;
		end--;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char arr[1000];
		scanf("%s",arr);
		int n = 0,high=0,i=0;
		n = length(arr);
		high = higest(arr,n);
		if(high != -1)
		{
			swap(arr,n,high);
			reverse(arr,high+1,n-1);
			for(i=0;i<n;i++)
				printf("%c",arr[i]);
		}
		else
		{
			printf("game terminated!");
		}

		printf("\n");
	}
	return 0;
}

/*
algorithm
from wikipedia :p 
1.Find the highest index i such that s[i] < s[i+1]. If no such index exists, the permutation is the last permutation.
2.Find the highest index j > i such that s[j] > s[i]. Such a j must exist, since i+1 is such an index.
3.Swap s[i] with s[j].
4.Reverse the order of all of the elements after index i till the last element.
*/