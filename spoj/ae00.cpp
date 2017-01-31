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
int nodivisor(long long int a)
{
	long long int ans=1;
	for(int i=2;i<=a;i++)
	{
		int exp=0;
		while(a%i==0){exp++;a/=i;}
		ans*=(exp+1);
	}//cout<<ans<<"no of divisors \n ";  //every no can be written as a=p^x*q^y....where p,q,...are prime nos..so.no ofdivisors is (x+1)(y+1)...
	return ans;
}
int main(){
	long long int a,ans=0;
	cin>>a;
	for(int i=1;i<=a;i++){

		if(nodivisor(i)%2==0){ans=ans+nodivisor(i)/2;}
				else {ans=ans+nodivisor(i)/2+1;}
			}
			cout<<ans;
			return 0;
		}