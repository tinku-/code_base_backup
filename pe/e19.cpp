#include <iostream>
using namespace std;
bool leap(int x)
{
	bool f=false;
	if(x%4==0 && x%100!=0 || x%400==0)f=true;
	return f;
}
int main()
{
	long long int x,y,l,days=0,ans=0;
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int b[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	cin>>x>>y>>l;days=l-1;
	for(int i=x;i<=y;i++)
	{
		cout<<i<<":";
		if(leap(i)==true)
		{for(int j=0;j<12;j++)
			{if(days%7==6){cout<<j<<" ";ans++;}days=days+b[j];}}
		else
		{for(int j=0;j<12;j++)
			{if(days%7==6){cout<<j<<" ";ans++;}days=days+a[j];}}
		cout<<"\n";	
	}
	cout<<"\n\n"<<ans<<"\n\n";return 0;
}


/*
input :1901 2000
output:171 
//that is 171 times in 20th century sunday was on 
//begning of the month
*/