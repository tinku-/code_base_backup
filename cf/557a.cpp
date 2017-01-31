#include <iostream>
using namespace std;
int main()
{
	long long int n,mx1,mi1,mx2,mi2,mx3,mi3,m1=0,m2=0,m3=0;
	cin>>n>>mi1>>mx1>>mi2>>mx2>>mi3>>mx3;
	if((mi2+mi3)>=(n-mx1)){m1=n-mi2-mi3;n=n-m1;}
	else {m1=mx1;n=n-m1;}
	if(mi3>=(n-mx2)){m2=n-mi3;n=n-m2;m3=n;}
	else {m2=mx2;n=n-m2;m3=n;}
	cout<<m1<<" "<<m2<<" "<<m3;
	return 0;
}