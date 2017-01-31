#include <cstring>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
using namespace std;
int sumd(long long int a)
{
	long long int d=0;
	for(int i=1;i<a;i++)if(a%i==0)d=d+i;
	return d;
}
int check(long long int num)
{
    long long int i;
    if(num<=1)
        return 0;
    if(num==2)
        return 1;
    if(num%2==0)
        return 0;
    long long int sRoot = sqrt(num*1.0);
    for(i=3; i<=sRoot; i+=2)
    {
        if(num%i==0)
            return 0;
    }
    return 1;
}

int main(){
	long long int t=0;cin>>t;
	for(int i=0;i<t;i++){
		long long int n;cin>>n;
		if(check(sumd(n))==1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
