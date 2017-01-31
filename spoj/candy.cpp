#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <stdio.h>
#include <algorithm>
using namespace std;
int candy(long long int x){
	long long int a[x];long long int sum=0,ave=0,ans=0;
	for(int i=0;i<x;i++){cin>>a[i];sum=sum+a[i];}
	if(sum%x!=0){cout<<-1<<"\n";return 0;}
	else 
		{ave=sum/x;
			for(int i=0;i<x;i++)
			{if(a[i]>ave){ans=ans+a[i]-ave;}}
		}cout<<ans<<"\n";return 0;}
int main(){
	long long int x;
	for(;;)
	{
		cin>>x;if(x!=-1){candy(x);}else{return 0;}
	}
	return 0;
}