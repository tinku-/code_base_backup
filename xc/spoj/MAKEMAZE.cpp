#include <cstdio>
using namespace std;
int A[20][20],is[401],js[401],n,m;
bool is_valid(int oi,int oj)
{
	
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%c",&A[i][j]);
			}
		}
		int count=0,oi,oj;
		for(int i=0;i<n;i++)
		{
			if(A[0][i]=='.')
			{
				count++;
				oi=0;
				oj=i;
			}
			if(A[m-1][i]=='.')
			{
				count++;
				oi=m-1;
				oj=i;
			}
		}
		for(int i=1;i<m-1;i++)
		{
			if(A[i][0]=='.')
			{
				count++;
				oi=i;
				oj=0;
			}
			if(A[i][n-1]=='.')
			{
				count++;
				oi=i;
				oj=n-1;
			}
		}
		if(count!=2)
		{
			printf("invalid\n");
			continue;
		}
		else
		{
			if(is_valid(oi,oj))
				printf("valid\n");
			else
				printf("invalid\n");
		}
	}
	return 0;
}