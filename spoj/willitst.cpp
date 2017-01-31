#include <bits/stdc++.h>
using namespace std;
bool powerof2(long long int x)
{
	if(x == 0)
		return true;
	if((x&(x-1)) == 0)
		return true;
	return false;

}
int main()
{
	long long int n;cin>>n;
	if(powerof2(n) == true)
		cout<<"TAK";
	else
		cout<<"NIE";
}