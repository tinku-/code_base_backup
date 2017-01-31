#include <bits/stdc++.h>
using namespace std;
int main()
{
	int initial=0,y=0;
	int x =0,ans=0;
	cin>>y>>x;
	while(y != x)
	{
		if(x<y)
			y--;
		else
			y *= 2;
		ans++;
	}
	cout<<ans;
}