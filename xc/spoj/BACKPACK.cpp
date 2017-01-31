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
using namespace std;
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
struct good
{
	int volume,importance;
};
struct parent
{
	good self;
	int child_count;
	good child_list[3];
};
int main()
{
	freopen("spojinp.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		//stupid input. takes 20+ lines of code
		int v_max,n;
		cin>>v_max>>n;
		v_max/=10;
		int x,counter=-1;
		vector <parent> A;
		parent tpar;
		good temp;
		map <int,int> par_num;
		for (int i = 0; i < n; ++i)
		{
			cin>>temp.volume>>temp.importance>>x;
			temp.volume/=10;
			temp.importance*=temp.volume;
			if(x==0)
			{
				counter++;
				par_num[i+1]=counter;
				tpar.self=temp;
				tpar.child_count=0;
				A.push_back(tpar);
			}
			else
			{
				x=par_num[x];
				A[x].child_list[A[x].child_count]=temp;
				A[x].child_count++;
			}
		}
		// just focus on what happens beneath this part.
		n=A.size();
		int dp[n+1][v_max+1];
		for (int i = 0; i < v_max+1; ++i)
		{
			dp[0][i]=0;
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j <= v_max; ++j)
			{
				dp[i][j]=dp[i-1][j];
				if(j>=A[i-1].self.volume)
				{
					for (int mask = 0; mask < (1<<A[i-1].child_count); ++mask)
					{
						int wt=A[i-1].self.volume,val=A[i-1].self.importance;
						for (int k = 0; k < A[i-1].child_count; ++k)
						{
							if(mask & (1<<k))
							{
								wt+=A[i-1].child_list[k].volume;
								val+=A[i-1].child_list[k].importance;
							}
						}
						if(j>=wt)
							dp[i][j]=max(dp[i][j],dp[i-1][j-wt]+val);
					}
				}
			}
		}
		cout<<dp[n][v_max]*10<<"\n";
	}
	return 0;
}