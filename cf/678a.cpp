#include <bits/stdc++.h>
bool leap(int x)
{
	if(x%4 == 0 && x%100 != 0)
		return true;
	if(x%100 == 0 && x%400 == 0)
		return true;
	else
		return false;
}
using namespace std;
int main()
{
	long long int n,i=1;
	cin>>n;
	if(leap(n) == true)
		cout<<n+28;
	else
	{
		n++;
		while(i%7 != 0 )
		{
			//cout<<"lol";
			if(leap(n) == true)
				i += 2;
			else
				i++;
			n++;
			if(i%7 == 0 && leap(n) == true)
				{i += 2;n++;}

		}
		cout<<n;
	}
}