#include <iostream>
using namespace std;
string f(string x)
{
	int c=0;
	string ans="";
	for(int i=0;i<x.length();i++)
	{
		c*=10;
		c+=(x[i]-'0');
		ans+=(char)(c/9+'0');
		c%=9;
	}
	if(c==0)
	{
		if(ans[0]=='0')
			ans.erase(0,1);
		return ans;
	}
	c=1;
	int al=ans.length();
	for(int i=al-1;i>=0;i--)
	{
		if(c==0)
			break;
		if(ans[i]=='9')
		{
			ans[i]='0';
			c=1;
		}
		else
		{
			ans[i]=(char)(ans[i]+1);
			c=0;
		}
	}
	if(c==1)
		ans='1'+ans;
	if(ans[0]=='0')
		ans.erase(0,1);
	return ans;
}
int main()
{
	string x;
	cin>>x;
	while(x!="-1")
	{
		if(x=="0")
			cout<<"0\n";
		else
			cout<<f(x)<<"\n";
		cin>>x;
	}
	return 0;
}