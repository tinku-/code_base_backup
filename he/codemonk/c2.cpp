#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
long long int a,b,c,k;
long long int P(long long int x)
{
	return a*x*x + b*x + c;
}
long long int poly(long long int start,long long int end)
{
	if(P(0) > k)
		return 0;
	while(start <= end)
	{
		long long int mid = (start + end)/2;
		if( (P(mid) >= k && P(mid-1) < k) || (P(mid) >= k && mid == 0) )
			return mid;
		else if(P(mid) < k)
			start = mid + 1;
		else
			end = mid - 1;
	}
}
int main()
{
	long long int t;cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>k;
		cout<<poly(0,MAX)<<endl;
	}
	return 0;
}