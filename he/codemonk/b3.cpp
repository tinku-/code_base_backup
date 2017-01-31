#include <iostream>
using namespace std;
#define MAX 1000000
int arr[MAX];
int merge(int left[],int l,int right [],int r)
{
	int i=0,j=0,k=0;
	while(i<l && j<r)
	{
		if(left[i] > right[j])
		{
			arr[k] = left[i];
			k++;i++;
		}
		else
		{
			arr[k] = right[j];
			k++;j++;
		}
	}
	while(i<l)
	{
		arr[k] = left[i];
		k++;i++;
	}
	while(j<r)
	{
		arr[k] = right[j];
		k++;j++;
	}
	return k;
}

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int l,r;
		for(int i=0;i<MAX;i++)
			arr[i] = 0;
		cin>>l>>r;
		int left[l];
		int right[r];
		for(int i=0;i<l;i++)
			cin>>left[i];
		for(int i=0;i<r;i++)
			cin>>right[i];
		int k = merge(left,l,right,r);
		for(int i=0;i<k;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
}