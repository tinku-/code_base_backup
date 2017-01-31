#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX 1000000
using namespace std;
long long int counter;
void merge(long long int arr[],long long int n,long long int left[],long long int l,long long int right[],long long int r)
{
	long long int i=0,j=0,k=0,count=0;
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
			counter += count;
			arr[k] = left[i];
			k++;i++;
		}
	}
	while(i<l)
	{
		counter += count;
		arr[k] = left[i];
		k++;i++;
	}
	while(j<r)
	{
		arr[k] = right[j];
		k++;j++;
	}
}
void mergesort(long long int arr[],long long int n)
{
	if(n>1)
	{
		long long int mid = n/2;
		long long int left[mid];
		long long int right[n-mid];
		for(long long int i=0;i<mid;i++)
			left[i] = arr[i];
		for(long long int i=mid;i<n;i++)
			right[i-mid] = arr[i];
		mergesort(left,mid);
		mergesort(right,n-mid);
		merge(arr,n,left,mid,right,n-mid);
	}
}	
int main()
{
	long long int t;cin>>t;
	while(t--)
	{
		long long int n;cin>>n;
		long long int arr[n];
		counter = 0;
		for(long long int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		mergesort(arr,n);
		cout<<counter<<endl;
	}
}	