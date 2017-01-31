 #include <bits/stdc++.h>
using namespace std;
long long int C(long long int n,long long int k)
{
	long long int i = 1,ans = 1;
	long long int a = max(n-k,k);
	while(n > a)
	{
		ans = (ans*n)/i;
		i++;
		n--;
	}
	return ans;
}
int main()
{
	long long int n,k;
	int t;cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cout<<C(n-1,k-1)<<endl;
	}
	return 0;
}