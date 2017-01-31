#include <iostream>
#include <string>
using namespace std;

string recursion(long long int x)
{
	string s = "";
	string t = "";
	long long int i=0;
	if(x == 0)
		return "0";
	if(x == 1)
		return "1";
	if(x == 2)
		return "2";

	while(x)
	{
		if(x%2 == 1)
		{
			string t = "";
			t = recursion(i);
		}		
		i++;
		x=x/2;
		if(s != "")
			s = s + "+" + t;
		else
			s = t;
	}
	s = "2(" + s + ")";
	return s;
}
int main()
{
	long long int a;
	cin>>a;
	string s= recursion(a);
	cout<<s;
}