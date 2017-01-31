#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
int main()
{
	long long int t;
	long long int temp;
	cin>>t;
	while(t--)
	{
		long long int n,k,ans = 0,top = 0;
		cin>>n>>k;
		priority_queue <long long int> pq;		
		for(long long int i=0;i<n;i++)
		{
			cin>>temp;
			pq.push(temp);
		}
		for(long long int i=0;i<k;i++)
		{
			top = pq.top();
			pq.pop();
			ans += top;
			top = top/2;
			pq.push(top);
		}
		cout<<ans<<endl;
	}
	return 0;
}