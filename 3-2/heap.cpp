#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
//cormen heap sort 
int heap[100];
int hsize = 0;
void max_heapify(int heap[],int i)
{
	int temp,largest;
	int left = 2*i;
	int right = 2*i+1;
	if(left <= hsize && heap[left] > heap[i])
		largest = left;
	else
		largest = i;
	if(right <= hsize && heap[right] > heap[largest])
		largest = right;
	if(largest != i)
	{
		temp = heap[i];
		heap[i] = heap[largest];
		heap[largest] = temp;

		max_heapify(heap,largest);
	}
}
void build_heap(int heap[],int n)
{
	hsize = n;
	for(int i=n/2;i>0;i--)
		max_heapify(heap,i);
}
void heap_sort(int heap[],int n)
{
	int temp;
	build_heap(heap,n);
	for(int i=n;i>0;i--)
	{
		temp = heap[i];
		heap[i] = heap[1];
		heap[1] = temp;

		hsize--;
		max_heapify(heap,1);
	}
}
int main()
{
	heap[0] = 99999;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>heap[i+1];
	heap_sort(heap,n);
	for(int i=0;i<n;i++)
		cout<<heap[i+1]<<" ";
	cout<<endl;
	return 0;
}
