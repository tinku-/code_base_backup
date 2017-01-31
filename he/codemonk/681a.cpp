#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
	string s;int a,b;
	int flag = 1;
	for(int i=0;i<n;i++)
	{
		cin>>s>>a>>b;
		if(a >= 2400)
			flag = 1;
		if(b > a && flag == 1)
			flag = 2;
	}
	if(flag == 2)
		cout<<"YES";
	else
		cout<<"NO";
}