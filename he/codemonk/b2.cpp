#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX 1000000
using namespace std;
int brr[MAX] = {0};
int crr[MAX] = {0};
int counter = 0;
int merge(int arr[],int n,int left[],int l,int right[],int r)
{
	int i=0,j=0,k=0,count=0;
	while(i<l && j<r)
	{
		if(right[j] < left[i])
		{
			count++;
			arr[k] = right[j];
			k++;j++;
		}
		else
		{
			brr[left[i]] += count;
			arr[k] = left[i];
			k++;i++;
		}
	}
	while(i<l)
	{
		brr[left[i]] += count;
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
		int mid = n/2;
		int left[mid];
		int right[n-mid];
		for(int i=0;i<mid;i++)
			left[i] = arr[i];
		for(int i=mid;i<n;i++)
			right[i-mid] = arr[i];
		mergesort(left,mid);
		mergesort(right,n-mid);
		merge(arr,n,left,mid,right,n-mid);
	}
}	
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		int arr[n];
		for(int i=0;i<MAX;i++)
			brr[i] = 0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			crr[i] = arr[i];
		}
		mergesort(arr,n);
		for(int i=0;i<n;i++)
			cout<<brr[crr[i]]<<" ";
		printf("\n");
	}
}	