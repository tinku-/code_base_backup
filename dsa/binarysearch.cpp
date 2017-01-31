#include <iostream>
#include <stdio.h>
using namespace std;
int bianrysearch(int a[],int n,int x,int l,int r){
	while(l<=r){
		int mid= l+(r-l)/2;
		if(a[mid]==x)return mid;
		if(a[mid]<x)l=mid+1;
		if(a[mid]>x)r=mid-1;
	}return -1;
}
int main(){
	int n,x;cin>>n>>x;int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<bianrysearch(a,n,x,0,n-1);
}