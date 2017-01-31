#include <iostream>
using namespace std;
int main()
{
	long long int a,b,ans;
	string s;
	cin>>a>>b;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i] == '1')
			ans = ((ans%b)+(a%b))%b;
		a = ((a%b)*(a%b))%b;
	}
	cout<<ans;
}