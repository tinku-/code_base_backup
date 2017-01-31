#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,m,k,i=0,ans=1,placed = 0;
	cin>>n>>m>>k;
	if(n == 1)
	{
		cout<<m;
		return 0;
	}
	m = m-n;
	long long int l = k-1 , r = n - k;
	while(placed <= m)
	{
		if(placed >= ( l*(l-1)/2 + r*(r-1)/2) + max(l,r) + 1)
		{
			m = m - (l*(l-1)/2 + r*(r-1)/2 + max(l,r) + 1);
			ans += m/n;
			break;
		}
		else
		{
			if(i <= l)
				placed += i;
			else
				placed += l;
			if(i <= r)
				placed += i;
			else
				placed += r;
			placed++;
			ans++;
			i++;
		}
		//cout<<placed<<" ";
	}
	cout<<ans-1;
}