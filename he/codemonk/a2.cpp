#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
	int t=0;cin>>t;
	while(t--)
	{
		string s;cin>>s;
		vector <char> v;
		for(int i=0;i<s.size();i++)
			v.push_back(s[i]);
		int i=0;
		while(i < (v.size()-1))
		{
			if(v[i] != v[i+1])
				i++;
			else
				v.erase (v.begin()+i+1);
		}
		for(int i=0;i<v.size();i++)
			cout<<v[i];
		cout<<endl;
	}
}