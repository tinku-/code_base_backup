#include <iostream>
#include <cmath>
using namespace std;
int arr[32] = {-1};
int main()
{
	int n;
	cin>>n;
	int i=0;
	while(n)
	{
		if(n%2 == 1)
			arr[i] = i+1;
		n = n/2;
		i++;
	}
	while(i--)
	{
		if(arr[i] != -1 && arr[i] != 0)
			cout<<arr[i]<<" ";
	}

}