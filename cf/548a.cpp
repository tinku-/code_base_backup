#include <iostream>
#include <string>
using namespace std;
bool pcheck(string s)
{
	bool f=false;
	for(int i=0;i<s.size()/2;i++)
		{if(s[i]!=s[s.size()-i-1]){return f;}}
	f=true;
	return f;
}
int main()
{
	int k,a=0,t=0;
	string s;
	cin>>s>>k;
	if(s.size()%k!=0){cout<<"NO";return 0;}
	else
		{
			for(int i=0;i<=(s.size()-(s.size()/k));i=i+(s.size()/k))
				if(pcheck(s.substr(i,(s.size()/k)))==false){cout<<"NO";return 0;}
			cout<<"YES";
		}
	return 0;
}