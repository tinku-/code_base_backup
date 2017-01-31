#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		set <string> s1;
		string s;
		int n,h;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			if(s1.find(s) != s1.end())
				h++;
			else
				s1.insert(s);
		}
		set<string>:: iterator it;
   		for(it=s1.begin();it!=s1.end();it++)
       		cout<<*it<<endl;
	}
}