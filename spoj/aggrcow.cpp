#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;
int f(long long int a[],long long int n,long long int x,long long int c){
	long long int cow=1;
	{
		//cout<<endl<<"i="<<i<<endl;
		long long int temp=a[0];
		for(int j=1;j<n;j++)
		{
			if(a[j]-temp>=x)
			{
				cow++;temp=a[j];//cout<<"j="<<j<<" ";
			}
		}if(cow==c)return 1;
		 cow=1;
	}return 0;
}

int cows(long long int a[],long long int n,long long int c){
	long long int l=a[0],h=a[n-1];
	while(l<h){
		int mid=(h+l)/2;
		if(f(a,n,mid,c)==1)
			l=mid+1;
		else
			h=mid;
	}return l-1;
}
int main(){
	long long int t;cin>>t;
	for(int i=0;i<t;i++)
	{
		long long int n,c;cin>>n>>c;
		long long int a[n];
		for(int i=0;i<n;i++){cin>>a[i];}
		sort(a,a+n);
		cout<<cows(a,n,c)<<endl;
	}
	return 0;
}