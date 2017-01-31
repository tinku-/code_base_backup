#include <bits/stdc++.h>
using namespace std;
int counter(int n)
{
	int i=0;
	while(n)
	{
		n = n&(n-1);
		i++;
	}
	return i;
}
int
 main()
{
  int t=0;cin>>t;
  while(t--)
  {
  	int n,k,x,ans = 0;
  	cin>>n>>k;
  	pair<int, int> paa[n];
  	for(int i=0;i<n;i++)
  	{
  		cin>>x;
  		paa[i].first = counter(x);
  		paa[i].second = x; 
  	}
  	sort(paa,paa+n);
 // 	for(int i=0;i<n;i++)
 //		cout<<paa[i].first<<" "<<paa[i].second<<endl;
  	for(int i=0;i<k;i++)
  		ans += paa[n-1-i].first;
  	cout<<ans<<endl;
  }
}