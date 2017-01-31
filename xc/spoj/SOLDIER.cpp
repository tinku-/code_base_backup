#include <vector>
#include <list>
#include <map>
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
#include <cstring>
#include <queue>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;
struct equipment
{
	int val,wt;
};
bool sorter(const equipment &x,const equipment &y)
{
	return x.wt<y.wt;
}
int main()
{
	freopen("spojinp.txt","r",stdin);
	int n,t,x;
	cin>>n>>t;
	equipment temp;
	vector < vector <equipment> > A(6);
	for (int i = 0; i < n; ++i)
	{
		cin>>x>>temp.wt>>temp.val;
		if(x>=1 && x<=6)
			A[x-1].push_back(temp);
	}
	for (int i = 0; i < 6; ++i)
	{
		if(A[i].empty())
		{
			cout<<"0";
			return 0;
		}
		sort(A[i].begin(), A[i].end(),sorter);
	}
	int money_used=0;
	vector <int> curr_item(6,0);
	for (int i = 0; i < 6; ++i)
	{
		money_used+=A[i][0].wt;
	}
	bool flag=true;
	while(flag)
	{
		int worst_item=0;
		for (int i = 1; i < 6; ++i)
		{
			if(A[i][curr_item[i]].val<A[worst_item][curr_item[worst_item]].val)
				worst_item=i;
		}
		flag=false;
		for (int i = curr_item[worst_item]+1; i < A[worst_item].size(); ++i)
		{
			if(A[worst_item][i].val>A[worst_item][curr_item[worst_item]].val && money_used+A[worst_item][i].wt-A[worst_item][curr_item[worst_item]].wt<=t)
			{
				flag=true;
				curr_item[worst_item]=i;
				break;
			}
		}
	}
	int worst_item=0;
	for (int i = 1; i < 6; ++i)
	{
		if(A[i][curr_item[i]].val<A[worst_item][curr_item[worst_item]].val)
			worst_item=i;
	}
	cout<<A[worst_item][curr_item[worst_item]].val;
	return 0;
}