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
	long long int a[n],h1[n-1],h2[n-1],root[n];
	for(int i=0;i<n-1;i++)
		cin>>h1[i];
	for(int i=0;i<n-1;i++)
		cin>>h2[i];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		root[i]=0;
		root[i]=root[i]+a[i];
		for(int j=0;j<i;j++)
			root[i]=root[i]+h1[j];
		for(int k=i;k<n-1;k++)
			root[i]=root[i]+h2[k];
	}sort(root,root+n);
	cout<<(root[0]+root[1]);
	return 0;
}
