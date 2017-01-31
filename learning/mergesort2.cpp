#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
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
void mergesort(int ar[],int l,int r){
	while(l<r){
		int mid=l+(r-l)/2;
		mergesort(ar,l,mid);
		mergesort(ar,mid+1,r);
		merge(ar,l,mid,r);
	}
}
int main(){
	int n;cin>>n;
	int ar[n];
	for(int i=0;i<n;i++)
		cin>>ar[i];
	mergesort(ar,0,n-1);
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<ar[i];
	return 0;
}