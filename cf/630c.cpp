#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long long int count =0;
	int n;
	cin>>n;
	while(n)
		{count += pow(2,n);n--;}
	cout<<count;
}