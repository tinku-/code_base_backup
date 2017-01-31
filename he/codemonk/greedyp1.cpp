#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long int sum = 0;
	long long int s[n];
	long long int c[n];
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
		cin>>c[i];
	sort(c,c+n);
	sort(s,s+n);
	for(int i=0;i<n;i++)
	{
		sum += c[i]*s[i];
	}
	//cout<<fixed<<setprecision(0);
	cout<<sum<<endl;
}