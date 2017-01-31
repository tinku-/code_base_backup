#include <iostream>
using namespace std;
int safe()
{
	int x;cin>>x;
	for(int i=2;i*i<x;i++)
	{
		if(x%i == 0)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		if(safe() == 1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}