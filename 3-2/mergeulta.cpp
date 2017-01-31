#include <iostream>
using namespace std;
void merge(int arr[],int n,int left[],int l,int right[],int r)
{
	int i=0,j=0,k=0;
	while(i<l && j<r)
	{
		if(left[i] >= right[j])
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
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	mergesort(arr,n);
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}