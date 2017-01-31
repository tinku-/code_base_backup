#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,A[50][50];
int shortest_path(int s,int d)
{
	int num_visited=0,least_dist,least_dist_pos,x;
	vector <int> SP(n,1000000000),visited(n,0);
	SP[s]=0;
	while(visited[d]==0)
	{
		least_dist_pos=-1;
		least_dist=1000000001;
		for(int i=0;i<n;i++)
		{
			if(visited[i]==0)
			{
				if(SP[i]<least_dist)
				{
					least_dist=SP[i];
					least_dist_pos=i;
				}
			}
		}
		visited[least_dist_pos]=1;
		for(int i=0;i<n;i++)
		{
			if(visited[i]==0)
			{
				x=SP[least_dist_pos]+A[least_dist_pos][i];
				if(x<SP[i])
					SP[i]=x;
			}
		}
	}
	return SP[d];
}
int main()
{
	int t,r,s,d;
	scanf("%d",&t);
	for(int case_no=1;case_no<=t;case_no++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				scanf("%d",&A[i][j]);
		}
		scanf("%d",&r);
		int ans=0;
		while(r--)
		{
			scanf("%d%d",&s,&d);
			ans+=shortest_path(s-1,d-1);
		}
		printf("Case #%d: %d\n",case_no,ans);
	}
	return 0;
}