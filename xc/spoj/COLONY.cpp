#include <iostream>
#include <cmath>
using namespace std;
string opposite(string x)
{
	if(x=="red")
		return "blue";
	else
		return "red";
}
string f(long long int y, long long int p)
{
	if(y==0)
		return "red";
	long long int hl=(long long int)(pow(2,y-1));
	if(p<hl)
		return opposite(f(y-1,p));
	else
		return f(y-1,p-hl);
}
int main()
{
	long long int y,p;
	cin>>y>>p;
	cout<<f(y,p);
	return 0;
}