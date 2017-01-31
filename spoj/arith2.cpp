#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;while(t--)
	{
		long long int i=0,n,ans,temp;
		char c,tempc;
		while(1)
		{
			i++;
			cin>>n>>c;
			if(i == 1)
			{
				temp = n;
				tempc = c;
			}
				else
			{
				if(tempc == '+')
				{
					temp += n;
					tempc = c;
					//cout<<temp<<endl;
				}
				else if(tempc == '-')
				{
					temp -= n;
					tempc = c;
					//cout<<temp<<endl;
				}
				else if(tempc == '*')
				{
					temp *= n;
					tempc = c;
					//cout<<temp<<endl;
				}
				else if(tempc == '/')
				{
					temp /= n;
					tempc = c;
					//cout<<temp<<endl;	
				}
				if(c == '=')
				{
					cout<<temp<<endl;
					break;
				}
			}
		}
	}
}