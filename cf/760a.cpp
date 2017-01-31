#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m;int d;cin>>m>>d;
	if(m == 1)
		m = 31;
	else if(m == 2)
		m = 28;
	else if(m == 3)
		m = 31;
	else if(m == 4)
		m = 30;
	else if(m == 5)
		m = 31;
	else if(m == 6)
		m = 30;
	else if(m == 7)
		m = 31;
	else if(m == 8)
		m = 31;
	else if(m == 9)
		m = 30;
	else if(m == 10)
		m = 31;
	else if(m == 11)
		m = 30;
	else if(m == 12)
		m = 31;
	cout<<ceil((double)(m-(8-d))/7)+1;
}