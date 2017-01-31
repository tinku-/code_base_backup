#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int a;
	string s;
	cin>>s;
	a=s.find("WUB");
	while( a != -1)
	{
		s.replace(a,3," ");
		a=s.find("WUB");
		//cout<<a<<endl;
	}
	cout<<s;
}