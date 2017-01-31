#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	long long int n,sum=0,t1=1,t2=2;
	cin>>n;
	while(t2<n)
	{
		if(t2%2==0)sum=sum+t2;
		t2=t1+t2;
		t1=t2-t1;
		cout<<t1<<" ";
	}
	cout<<"\n\n\n"<<sum<<"\n";
	return 0;
}
