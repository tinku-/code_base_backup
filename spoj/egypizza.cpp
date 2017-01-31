#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,x=0,y=0,z=0,ans=1;
	string str;
	string str1 ("1/4");
	string str2 ("1/2");
	string str3 ("3/4");
	cin>>t;
	while(t--)
	{
		cin>>str;
		if(str.compare(str1) == 0)
			z++;
		else if(str.compare(str2) == 0)
			x++;
		else
			y++;
	}
	//cout<<x<<" "<<y<<" "<<z<<endl;
	ans += x/2;
	ans += x%2;
	ans += y;
	x = x%2;
	z = z - 2*x - y;
	if(z > 0)
		ans += (int)ceil((double)z/4);
	cout<<ans;
	return 0;
}