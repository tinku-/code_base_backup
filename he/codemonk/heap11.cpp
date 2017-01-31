#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	priority_queue<int>q;
	cin>>n;
	long long int arr[n];
	long long int x,y,z;
	for(i = 0; i < n; i++) 
	{
		scanf("%lld",&arr[i]);
		q.push(arr[i]);
		if(q.size() < 3) 
		{
			printf("-1\n");
			continue;
		}

		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		z = q.top();
		q.pop();

		q.push(x);
		q.push(y);
		q.push(z);
		
		x = x*y;
		x = x*z;
		
		printf("%lld\n",x);
	}
	return 0;
}