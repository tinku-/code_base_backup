#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>
using namespace std;
int n;
vector < vector <int> > A;
bool get_path()
{
	deque <int> que,par;
	vector <int> visited(n,0);
	que.push_back(0);
	par.push_back(-1);
	visited[0]=1;
	bool ans=false;
	int pos=0;
	while(pos<que.size())
	{
		for(int i=0;i<n;i++)
		{
			if(A[que[pos]][i]>0&&visited[i]==0)
			{
				visited[i]=1;
				que.push_back(i);
				par.push_back(pos);
				if(i==n-1)
				{
					ans=true;
					break;
				}
			}
		}
		pos++;
		if(ans)
			break;
	}
	if(ans)
	{
		pos=que.size()-1;
		while(par[pos]!=-1)
		{
			A[que[par[pos]]][que[pos]]--;
			A[que[pos]][que[par[pos]]]++;
			pos=par[pos];
		}
	}
	return ans;
}
int main()
{
	int t,x,y,ans;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		vector <int> xyz(n,0);
		vector < vector <int> > abc(n,xyz);
		A=abc;
		scanf("%d",&x);
		for(int i=0;i<x;i++)
		{
			scanf("%d",&y);
			A[0][y-1]=1;
		}
		for(int i=1;i<n-1;i++)
		{
			scanf("%d",&x);
			for(int j=0;j<x;j++)
			{
				scanf("%d",&y);
				if(y==n)
					A[i][y-1]=1;
				else
					A[i][y-1]=n;
			}
		}
		while(get_path())
			ans++;
		printf("%d\n",ans);
	}
	return 0;
}