#include <bits/stdc++.h>
using namespace std;

int row[100001] = {0};
int col[100001] = {0};
int main()
{
	long long int n,m,cnt=0,r=0,c=0;
	long long int i,j,ans=0;
	cin>>n>>m;r=n;c=n;
	while(m--)
	{
		cin>>i>>j;
		i--;j--;
		cnt++;
		if(row[i] == 0)
			r--;
		if(col[j] == 0)
			c--;
		row[i] = 1;
		col[j] = 1;
		ans = c*r;
		cout<<ans<<" ";
	}
}