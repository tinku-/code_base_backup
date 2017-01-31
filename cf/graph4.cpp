#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int sum=0,x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		sum += x;
	}
	n--;
	n *= 2;
	if(n == sum)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}