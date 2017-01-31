#include <bits/stdc++.h>
using namespace std;
string rec(int x)
{
	string s = "";
	if(x == 2)
	{
		s = "2";
		return s;
	}
	if(x == 1)
	{
		s = "";
		return s;
	}
	if(x == 0)
	{
		s = "0";
		return s;
	}

	int i=0;
	while(x >= 1<<i)
	{
		if(x&(1<<i))
		{
			s ="2(" + rec(i) + ")" + "+" + s ;
		}
		i++;
	}
	return s;
}
int main()
{
	int arr[] ={137, 1315, 73, 136, 255, 1384, 16385};
	for(int t=0;t<7;t++){
	int x = arr[t];
	string s = rec(x),p;
	//cout<<s<<endl;
	for(int i=0;i<s.size()-1;i++)
	{
		if(s[i] == '+' && s[i+1] == ')')
			continue;
		else
			p += s[i];
	}
	for(int i=0;i<p.size()-1;i++)
	{
		if(p[i] == '(' && p[i+1] == ')')
		{
			p[i] = p[i+1] = '*';
		}
	}
	//cout<<x<<"="<<p<<endl;
	cout<<x<<"=";
	for(int i=0;i<p.size();i++)
	{
		if(p[i] != '*')
			cout<<p[i];
	}cout<<endl;}
}

/*

137=2(2(2)+2+2(0))+2(2+2(0))+2(0)
1315=2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
73=2(2(2)+2)+2(2+2(0))+2(0)
136=2(2(2)+2+2(0))+2(2+2(0))
255=2(2(2)+2+2(0))+2(2(2)+2)+2(2(2)+2(0))+2(2(2))+2(2+2(0))+2(2)+2+2(0)
1384=2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2)+2(2(2)+2(0))+2(2+2(0))
16385=2(2(2+2(0))+2(2)+2)+2(0)

*/
