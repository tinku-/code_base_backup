#include <iostream>
#include <set>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		set<int> s;
		set<int> :: iterator it;
		int n,x,y,ans=0;cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x>>y;
			s.insert(x);
			s.insert(y);
		}
		for(it=s.begin();it != s.end();++it)
		{
			ans++;
		}
		cout<<ans<<endl;		

	}
}	