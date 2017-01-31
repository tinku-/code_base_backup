#include <iostream>
#include <set>
using namespace std;
int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		set <long long int> s1;
		long long int a,b,x,y;
		cin>>a>>b;
		for(int i=0;i<a;i++)
		{
			cin>>x;
			s1.insert(x);
		}
		for(int i=0;i<b;i++)
		{
			cin>>y;
			if(s1.find(y) != s1.end())
				cout<<"YES"<<endl;
			else
			{
				s1.insert(y);
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}