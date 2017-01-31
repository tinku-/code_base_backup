#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	long long int n,sum1=0,sum2=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{sum1=sum1+i*i;}
    sum2=n*n*(n+1)*(n+1)/4;
    cout<<"\n"<<abs(sum1-sum2)<<"\n\n";
	return 0;
}
