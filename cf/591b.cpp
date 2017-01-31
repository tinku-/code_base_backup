#include <iostream>

using namespace std;
int main(){
	char alpha[26];
	long long int n,m;
	cin>>n>>m;
	string s;
	for(int i=0;i<26;i++)
		alpha[i]=i+'a';
	cin>>s;
	while(m--)
	{
		char x,y;
		cin>>x>>y;
		for(int i=0;i<26;i++)
		{
			if(alpha[i] == x)
				alpha[i] = y;
			else if(alpha[i] == y)
				alpha[i] = x;
		}
	}
	for(int i=0;i<n;i++)
			cout<<alpha[s[i]-'a'];
	return 0;
}

//good problem 