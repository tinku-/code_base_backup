/* C program for merge sort */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
 using namespace std;
/* Function to merge the two haves ar[l..m] and ar[m+1..r] of aray ar[] */
void merge(int ar[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arays */
    int L[n1], R[n2];
 
    /* Copy data to temp arays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = ar[l + i];
    for(j = 0; j < n2; j++)
        R[j] = ar[m + 1+ j];
 
    /* Merge the temp arays back into ar[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            ar[k] = L[i];
            i++;
        }
        else
        {
            ar[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        ar[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        ar[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the sub-aray
  of ar to be sorted */
void mergesort(int ar[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergesort(ar, l, m);
        mergesort(ar, m+1, r);
        merge(ar, l, m, r);
    }
}
 
 

 
/* Driver program to test above functions */
int main(){
	int n;cin>>n;
	int ar[n];
	for(int i=0;i<n;i++)
		cin>>ar[i];
	mergesort(ar,0,n-1);
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";
	return 0;
}