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
	long long int n,ans=0,temp=0,min=0,max=0;
	cin>>n;
	long long int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==1){
			min=i;break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[n-1-i]==1){
			max=n-1-i;break;
		}

	}
	for(int i=min;i<=max;i++)
	{
		if(a[i]==0 && a[i+1]==0)
			{temp++;temp++;}
	}
	if(min==max)
		{
			if(a[max]==0)
				cout<<0;
			else 
				cout<<1;
		}
	else
	{
		ans=max-min-temp+1;
		//cout<<"max"<<max<<"min"<<min<<"temp"<<temp<<endl;
		cout<<ans;
	}
	return 0;
}