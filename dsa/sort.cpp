#include <iostream>
using namespace std;
int arr[1000000];
int bubble(int n)
{
	//bubble sort.
	int temp = 0,steps =0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n-i-1;j++)
		{
			steps++;
			if(arr[j] > arr[j+1])
			{
				swap(arr[j],arr[j+1]);
			}

		}
	return steps;
}
int selection(int n)
{
	int temp = 0,steps = 0;
	for(int i=0;i<n;i++)
	{
		int minimum = i;
		for(int j=i+1;j<n;j++)
		{
			steps++;
			if(arr[j] < arr[minimum])
			{
				minimum = j;
			}
		}
		swap(arr[minimum],arr[i]);
	}
}
int insertion(int n)
{
	int steps = 0;
	for(int i=0;i<n;i++)
	{
		int temp = arr[i];
		int j = i;
		while(arr[j-1] > temp && j > 0)
		{
			steps++;
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = temp;
	}
	return steps;
}
int main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	//cout<<"bubble "<<bubble(n)<<endl;
	for(int i=0;i<n;i++)
	{
		//cout<<arr[i]<<" ";
	}
	//cout<<"selection "<<selection(n)<<endl;
	for(int i=0;i<n;i++)
	{
	// 	cout<<arr[i]<<" ";
	}	
	cout<<"insertion "<<insertion(n)<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}	
	return 0;
}