#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
	string s;
	int a,b;
	int flag = 0;
	for(int i=0;i<n;i++)
	{
		cin>>s>>a>>b;
		if(a >= 2400 && b > a)
			flag = 1;
	}
	if(flag == 1)
		cout<<"YES";
	else
		cout<<"NO";
}