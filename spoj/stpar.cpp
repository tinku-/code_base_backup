#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(n == 0)
			return 0;
		queue<int> qu;
		stack<int> st;
		bool flag = false;
		int x=0,temp;

		while(n--)
		{
			cin>>temp;
			qu.push(temp);
		}
		
		while(!qu.empty())
		{

			if(qu.front() == x+1)
			{
				x++;
				qu.pop();
			}
			else if(!st.empty() && st.top() == x+1)
			{
				while(!st.empty() && st.top() == x+1)
				{
					x++;
					st.pop();
				}
			}
			else
			{
				//cout<<"go2"<<endl;
				if(st.empty() || st.top() > qu.front())
				{
					temp = qu.front();
					qu.pop();
					st.push(temp);
				}
				else if(!st.empty() && qu.front() > st.top())
				{
					cout<<"no"<<endl;
					flag = true;
					break;
				}
			}
		}
		if(flag == false)
			cout<<"yes"<<endl;

	}
}