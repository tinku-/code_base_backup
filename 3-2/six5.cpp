#include <stdio.h>
void merge(int arr[],int n,int left[],int l,int right[],int r)
{
	int i=0,j=0,k=0;
	while(i<l && j<r)
	{
		if(left[i] < right[j])
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
		int mid = n/2,i;
		int left[mid];
		int right[n-mid];
		for(i=0;i<mid;i++)
			left[i] = arr[i];
		for(i=mid;i<n;i++)
			right[i-mid] = arr[i];
		mergesort(left,mid);
		mergesort(right,n-mid);
		merge(arr,n,left,mid,right,n-mid);
	}
}
int firstoccurace(int arr[],int start,int end,int x)
{
	while(start <= end)
	{
		int mid = (start + end)/2;
		if((arr[mid] == x && arr[mid-1] < x) || (arr[mid] == x && mid==0))
			return mid;
		else if(arr[mid] >= x)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}
int main()
{
	int n1,n2,i;
	int a1[10000],a2[10000],temp[10000];
	int visited[10000] = {0};
	scanf("%d %d",&n1,&n2);
	for(i=0;i<n1;i++)
		{scanf("%d",&a1[i]);temp[i] = a1[i];}
	for(i=0;i<n2;i++)
		scanf("%d",&a2[i]);
	mergesort(temp,n1);
	/*
	for(i=0;i<n1;i++)
		printf("%d ",temp[i]);
	printf("\n");
	*/
	int index = 0;
	for(i=0;i<n2;i++)
	{
		int x = firstoccurace(temp,0,n1,a2[i]);
		//printf("%d\n",x );
		if(x != -1)
		{
			while(temp[x] == a2[i])
			{
				a1[index] = temp[x];
				index++;
				visited[x] = 1;
				x++;
			}
		}
	}
	for(i=0;i<n1;i++)
	{
		if(visited[i] == 0)
		{
			a1[index] = temp[i];
			index++;
		}
	}
	for(i=0;i<n1;i++)
		printf("%d ",a1[i]);
	printf("\n");
	return 0;
}
/*
input :
11 4
2 1 2 5 7 1 9 3 6 8 8
2 1 8 3
output:
2 2 1 1 8 8 3 5 6 7 9

input :
17 5
2 1 2 5 7 1 9 3 6 8 8 7 5 6 9 7 5
2 1 8 3 4
output :
2 2 1 1 8 8 3 5 5 5 6 6 7 7 7 9 9

input :
5 4
2 4 1 4 7
7 1 4 2
output :
7 1 4 4 2
*/

//time complexity of this algoridam is: O(n1 + n2log(n1))
/*
Let size of A1[] be m and size of A2[] be n.
1) Create a temporary array temp of size m and copy contents of A1[] to it.
2) Create another array visited[] and initialize all entries in it as false. visited[] is used to mark those elements in temp[] which are copied to A1[].
3) Sort temp[]
4) Initialize the output index ind as 0.
5) Do following for every element of A2[i] in A2[]
…..a) Binary search for all occurrences of A2[i] in temp[], if present then copy all occurrences to A1[ind] and increment ind. Also mark the copied elements visited[]
6) Copy all unvisited elements from temp[] to A1[].
*/

/*
http://www.geeksforgeeks.org/sort-array-according-order-defined-another-array/
*/