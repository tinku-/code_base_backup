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
using namespace std;
int n,m;
vector < vector <int> > A(100,vector <int> (100)),temp(100,vector <int> (100));
bool get_path(int s,int t)
{
	vector <int> parent(100,-1);
	parent[s]=s;
	stack <int> dfs;
	dfs.push(s);
	while(!dfs.empty())
	{
		int top=dfs.top();
		dfs.pop();
		if(top==t)
			break;
		for (int i = 0; i < 2*n; ++i)
		{
			if(temp[top][i] && parent[i]==-1)
			{
				parent[i]=top;
				dfs.push(i);
			}
		}
	}
	if(parent[t]==-1)
		return false;
	int pos=t;
	while(pos!=s)
	{
		temp[parent[pos]][pos]--;
		temp[pos][parent[pos]]++;
		pos=parent[pos];
	}
	return true;
}
int max_flow(int s,int t)
{
	int ans=0;
	while(get_path(s,t))
	{
		ans++;
	}
	return ans;
}
int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		char str[10];
		scanf("%d %d",&n,&m);
		for (int i = 0; i < 2*n-1; ++i)
		{
			for (int j = 0; j < 2*n-1; ++j)
			{
				A[i][j]=0;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			A[2*i][2*i+1]=1;
		}
		//input interconnections
		for (int i = 0; i < m; ++i)
		{
			scanf("%s",str);
			x=0,y=0;
			int pos=1;
			while(str[pos]!=',')
			{
				x=(x*10)+str[pos]-'0';
				pos++;
			}
			pos++;
			while(str[pos]!=')')
			{
				y=(y*10)+str[pos]-'0';
				pos++;
			}
			A[2*x+1][2*y]=1000000;
			A[2*y+1][2*x]=1000000;
		}
		//calculate max_flow b/w all pairs of points.
		int ans=n;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(!A[2*i+1][2*j])
				{
					temp=A;
					ans=min(ans,max_flow(2*i+1,2*j));
				}
			}
		}
		if(ans<n-1)
			printf("%d\n", ans);
		else
			printf("%d\n", n);
	}
	return 0;
}