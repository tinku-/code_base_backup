#include <bits/stdc++.h>
using namespace std;
int main()
{
	double a,b;
	for(;;)
	{
		cin>>a>>b;
		if(a == -1 && b == -1)
			return 0;
		if(a == 0 && b == 0)
			cout<<0<<endl;
		else if(a == b)
			cout<<1<<endl;
		else
			cout<<ceil((double)(max(a,b)/(min(a,b)+1)))<<endl;
	}
}