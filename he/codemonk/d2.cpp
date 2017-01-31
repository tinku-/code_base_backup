#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	stack <int> s;
	int x,q;
	cin>>q;
	while(q--)
	{
		cin>>x;
		if(x == 1)
		{
			if(s.empty())
			{
				cout<<"No Food"<<endl;
			}
			else
			{
				cout<<s.top()<<endl;
				s.pop();
			}
		}
		if(x == 2)
		{
			int p;
			cin>>p;
			s.push(p);
		}
	}
}