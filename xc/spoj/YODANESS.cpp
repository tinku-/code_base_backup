#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <map>
#include <vector>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;
bool sorter (const pair <int,int> &x,const pair <int,int> &y)
{
	return x.first>y.first;
}
int main()
{
	freopen("spojinp.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		map <string,int> M;
		int n,c=0;
		string temp;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			M[temp]=c;
			c++;
		}
		vector <int> A(n+1,0);
		vector < pair<int,int> > B(n);
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			B[i].first=M[temp];
			B[i].second=i;
		}
		sort(B.begin(), B.end(),sorter);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			ans+=n-1-B[i].second;
			int pos=n-B[i].second;
			while(pos>0)
			{
				ans+=A[pos];
				pos=pos-(pos & (pos*-1));
			}
			pos=n-B[i].second;
			while(pos<=n)
			{
				A[pos]--;
				pos=pos+(pos & (pos*-1));
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}