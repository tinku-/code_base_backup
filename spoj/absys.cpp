#include <bits/stdc++.h>
using namespace std;
int str_to_int(string s)
{
	int x=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-'0' > 9)
			return -999999;
		else
			x = x*10 + s[i]-'0';
	}
	return x;
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		string a,b,c,p,e;
		int x,y,z;
		cin>>a>>p>>b>>e>>c;
		x = str_to_int(a);
		y = str_to_int(b);
		z = str_to_int(c);
		if(x == -999999)
			x = z - y;
		else if(y == -999999)
			y = z - x;
		else if(z == -999999)
			z = x + y;


		cout<<x<<" + "<<y<<" = "<<z<<endl;
	}
}