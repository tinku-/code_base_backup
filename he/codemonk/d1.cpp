#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	queue <int> call,ideal;
	int n,x,time=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		call.push(x);
	}
	for(int i=0;i<n;i++)
	{
		cin>>x;
		ideal.push(x);
	}
	while(!ideal.empty())
	{
		if(call.front() == ideal.front())
		{
			time++;
			call.pop();
			ideal.pop();
		}
		else
		{
			time++;
			x = call.front();
			call.pop();
			call.push(x);
		}
	}
	cout<<time;
}	