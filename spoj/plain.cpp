#include <cstring>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <stdlib.h>
using namespace std;
int palin(string s)
{
	string p,t;
	p=s;
	t=s;
 
	for(int i=0;i<s.size();i++)
		t[i]='9';
	if(s==t) {
		cout<<1;
		for(int i=0;i<(s.size()-1);i++)
			cout<<0;
		cout<<1<<"\n";
	}
	else
{
	if(s.size()%2==0)
	{
		for(int i=0;i<s.size()/2;i++)
		{
			s[s.size()-1-i]=s[i];
		}
		int i=0,j=1;
		if(p>=s)
		{
		while(j==1)
		{
			if(s[s.size()/2-1-i]=='9')
			{
				s[s.size()/2-1-i]='0';
				s[s.size()/2+i]=s[s.size()/2-1-i];
				i++;
			}
			else
				{
					s[s.size()/2-1-i]++;
					s[s.size()/2+i]=s[s.size()/2-1-i];
					j=0;
				}
		}
        }
 
    }
    else
    {
    	for(int i=0;i<=s.size()/2;i++)
		{
			//cout<<i<<" ";
			s[s.size()-1-i]=s[i];
		}
		int i=0,j=1;
		if(p>=s)
		{
		while(j==1)
		{
			if(s[s.size()/2-i]=='9')
			{
				s[s.size()/2-i]='0';
				s[s.size()/2+i]=s[s.size()/2-i];
				i++;
			}
			else
				{
					s[s.size()/2-i]++;
					s[s.size()/2+i]=s[s.size()/2-i];
					j=0;
				}
		}
        }
 
    }
    cout<<s<<"\n";
}
}
int main()
{
	string x;
	long long int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>x;
	    x=palin(x);
	}
}