#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int f,h,w,mx=-100,mn=10000;
		cin>>f>>h>>w;
		long long int p[f+1];
		for(int i=0;i<f;i++)
		{
			cin>>p[i];
			mx = max(mx,p[i]);
		}
		p[f]=w;
		sort(p,p+f+1);
		for(int i=0;i<f;i++)
		{
			mn = min(mn,p[i+1]-p[i]);
		}
		mn = min(mn,p[0]);
		cout<<mn*h<<endl;
	}
	return 0;
}