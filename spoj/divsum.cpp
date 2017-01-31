#include <iostream>
using namespace std;
long long int divsum(long long int a)
{
	long long int divisor = 1;
	long long int sum = 0;
	if(a == 1 || a == 0)
		return sum;
	while(divisor < a)
	{
		if(a % divisor == 0)
			sum += divisor;
		divisor++;
	}
	return sum;
}
int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int a;
		cin>>a;
		cout<<divsum(a)<<endl;
	}
	return 0;
}