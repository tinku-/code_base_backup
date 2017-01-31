#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
using namespace std;
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
long long int n;
long long int mod=98765431;
pair <long long int,long long int> I(1,0);
long long int multiply(long long int x,long long int y)
{
	return (x*y)%mod;
}
pair <long long int,long long int> power(pair <long long int,long long int> a,int b)
{
	if(b==0)
		return I;
	if(b==1)
		return a;
	pair <long long int,long long int> ans=power(a,b/2);
	long long int x1=ans.first,x2=a.first,y1=ans.second,y2=a.second;
	ans.first=(multiply(x1,x1)+multiply(n-1,multiply(y1,y1)))%mod;
	ans.second=((2*multiply(x1,y1))+multiply(n-2,multiply(y1,y1)))%mod;
	x1=ans.first;
	y1=ans.second;
	if(b%2)
	{
		ans.first=(multiply(x1,x2)+multiply(n-1,multiply(y1,y2)))%mod;
		ans.second=(multiply(y1,x2)+multiply(x1,y2)+multiply(n-2,multiply(y1,y2)))%mod;
	}
	return ans;
}
int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%lld %d",&n,&t);
	long long int A[n],tsum=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld",&A[i]);
		tsum+=A[i];
	}
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	pair <long long int,long long int> ans(0,1);
	ans=power(ans,t);
	for (int i = 0; i < n; ++i)
	{
		printf("%lld\n",(multiply(ans.first,A[i])+multiply(ans.second,(tsum-A[i])%mod))%mod);
	}
	return 0;
}