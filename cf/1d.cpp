#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;
int main()
{
	long long int n=0;
	cin>>n;
	long long int a[n],c[n],sum=0,temp=0,k=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long int q=0;	
	cin>>q;
	long long int b[q];
	for(int i=0;i<q;i++)
	{
		cin>>b[i];
	}
	sort(a,a+n);
	c[0]=a[0];
	for(int i=1;i<n;i++)
	{
		c[i]=c[i-1]+a[i];
	}
	for(int i=0;i<q;i++)
	{

		temp=ceil(n/(b[k]+1.0));
		//cout<<"twf"<<temp;
		cout<<c[temp-1]<<endl;
		k++;
	}
	return 0;
}