#include <bits/stdc++.h>
using namespace std;
long long int sq(long long int x)
{
	int ans=0;
	while(x)
	{
		ans += (x%10)*(x%10);
		x = x/10;
	}
	return ans;
}
int main()
{
	long long int n,temp,ans=0;
	cin>>n;
	while(n != 1 && n != 4)
	{
		//cout<<n<<" ";
		n = sq(n);
		ans++;
	}
	if(n == 1)
		cout<<ans;
	else
		cout<<-1;
}