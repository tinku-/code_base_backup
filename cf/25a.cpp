#include <iostream>
using namespace std;
int main(){
	long long int n,a,temp;
	cin>>n;
	long long int arr[n];
	for(int i=0;i<n;i++)
	{	
		cin>>a;
		arr[i]=a%2;
	}
	temp = arr[0] + arr[n/2] + arr[n-1];
	if(temp >= 2)
	{
		for(int i=0;i<n;i++)
			if(arr[i] == 0)
				cout<<i+1;
	}
	if(temp <= 1)
	{
		for(int i=0;i<n;i++)
			if(arr[i] == 1)
				cout<<i+1;
	}
	return 0;
}