#include <bits/stdc++.h>
using namespace std;
int max_heapify(int arr[],int n,int i)
{
	int left = 2*i;
	int right = 2*i+1;
	int largest = i;
	if(left <= n && arr[left] > arr[largest])
		largest = left;
	if(right <= n && arr[right] > arr[largest])
		largest = right;
	if(largest != i)
	{
		swap(arr[i],arr[largest]);
		max_heapify(arr,n,largest);
	}
}
int min_heapify(int brr[],int n,int i)
{
	int left = 2*i;
	int right = 2*i+1;
	int largest = i;
	if(left <= n && brr[left] < brr[largest])
		largest = left;
	if(right <= n && brr[right] < brr[largest])
		largest = right;
	if(largest != i)
	{
		swap(brr[i],brr[largest]);
		min_heapify(brr,n,largest);
	}
}
int insert_max(int arr[],int n,int x)
{
	arr[n] = x;
	while(arr[n/2] < arr[n])
	{
		swap(arr[n],arr[n/2]);
		n = n/2;
	}

}
int insert_min(int brr[],int n,int x)
{
	brr[n] = x;
	while(brr[n/2] > brr[n])
	{
		swap(brr[n],brr[n/2]);
		n = n/2;
	}

}
int main()
{
	int n=0;
	int arr[100005],brr[100005];
	arr[0] = 999999;
	brr[0] = -999999;
	int q,x,y,z;
	cin>>q;
	while(q--)
	{	
		cin>>x;
		if(x == 1)
		{
			cin>>y;
			n++;
			insert_max(arr,n,y);
			insert_min(brr,n,y);
		}
		if(x == 2)
		{
			cin>>y;
			int flag = 0;
			for(int i=1;i<=n;i++)
				if(arr[i] == y)
				{
					flag = 1;
					swap(arr[i],arr[n]);
					n--;
					max_heapify(arr,n,i);
					break;
				}
			for(int i=1;i<=n;i++)
				if(brr[i] == y)
				{
					flag = 1;
					swap(brr[i],brr[n+1]);
					min_heapify(brr,n,i);
					break;
				}

			if(flag == 0)
				cout<<"-1"<<endl;
		}
		if(x == 3)
		{
			if(n>=1)
				cout<<arr[1]<<endl;
			else
				cout<<"-1"<<endl;
		}
		if(x == 4)
		{
			if(n>=1)
				cout<<brr[1]<<endl;
			else
				cout<<"-1"<<endl;
		}
		if(x == 5)
		{
			for(int i=1;i<=n;i++)
				cout<<arr[i]<<" ";
			cout<<endl;
			for(int i=1;i<=n;i++)
				cout<<brr[i]<<" ";
		}
	}

}