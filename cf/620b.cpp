#include <iostream>
using namespace std;
long long int segments(long long int x)
{
	long long int sum=0,i=0;
	while(x)
	{
		if(x%10 == 1)
			sum = sum + 2;
		if(x%10 == 7)
			sum = sum + 3;
		if(x%10 == 4)
			sum = sum + 4;
		if(x%10 == 2 || x%10 == 3 || x%10 == 5)
			sum = sum + 5;
		if(x%10 == 0 || x%10 == 6 || x%10 == 9)
			sum = sum + 6;
		if(x%10 == 8)
			sum = sum + 7;
		x = x/10;
	}
	return sum;
}
int main()
{
	long long int a,b;cin>>a>>b;
	long long int arr[b];arr[0] = 0;
	for(int i=1;i<=b;i++)
	{
		arr[i] = arr[i-1] + segments(i);
	}
	cout<<arr[b]-arr[a-1];
	return 0;
}