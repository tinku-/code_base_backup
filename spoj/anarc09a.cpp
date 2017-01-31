#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	int t=1,ans;
	while(1)
	{
		ans = 0;
		cin>>str;
		if(str[0] == '-')
			return 0;
		stack<int> s;
		for(int i=0;i<str.size();i++)
		{
			if(str[i] == '}') 
			{
				if(!s.empty() && s.top() == 1)
					s.pop();
				else
				{
					s.push(1);
					ans++;
				}
			}
			else
				s.push(1);
		}

		cout<<t++<<". "<<ans+s.size()/2<<endl;
	}
}