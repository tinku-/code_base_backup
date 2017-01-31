#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		priority_queue<int, vector<int>, greater<int> > v1,v2;
		int n,m,temp;
		cin>>n>>m;
		while(n--)
		{
			cin>>temp;
			v1.push(temp);
		}
		while(m--)
		{
			cin>>temp;
			v2.push(temp);
		}
		while(!v1.empty() && !v2.empty())
		{
			if(v1.top() < v2.top())
				v1.pop();
			else 
				v2.pop();
		}
		if(!v1.empty())
			cout<<"Godzilla"<<endl;
		else
			cout<<"MechaGodzilla"<<endl;
	}
}