#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int ans = 0;
	priority_queue<int> queue;
	int n,q,x;cin>>n>>q;
	while(n--)
	{
		cin>>x;
		queue.push(x);
	}
	while(q--)
	{
		ans += queue.top();
		x = queue.top();
		queue.pop();
		//cout<<x<<" ";
		x--;
		queue.push(x);
	}
	cout<<ans;
}