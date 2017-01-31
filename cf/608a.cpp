#include <iostream>
using namespace std;
int main()
{
	int n,f,fl,ti,time=0;
	cin>>n>>f;
	int arr[2000]={0};
	for(int i=0;i<n;i++)
	{
		cin>>fl>>ti;
		arr[fl] = ti;
	}
	for(int i=f;i>=0;i--)
	{
		if(arr[i] > (time))
			time += arr[i]-time;
		time++;
	}
	cout<<time-1;
}