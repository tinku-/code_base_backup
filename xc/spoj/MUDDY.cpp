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
char land[50][51];
int r,c,row_c,col_c,row_mat[50][50],col_mat[50][50],A[1252][1252];
bool get_path()
{
	vector <int> parent(col_c+2,-1);
	parent[0]=0;
	stack <int> dfs;
	dfs.push(0);
	while(!dfs.empty())
	{
		int top=dfs.top();
		dfs.pop();
		if(top==col_c+1)
			break;
		for (int i = 0; i < col_c+2; ++i)
		{
			if(A[top][i] && parent[i]==-1)
			{
				parent[i]=top;
				dfs.push(i);
			}
		}
	}
	if(parent[col_c+1]==-1)
		return false;
	int pos=col_c+1;
	while(pos!=0)
	{
		// printf("%d\n", pos);
		A[parent[pos]][pos]--;
		A[pos][parent[pos]]++;
		pos=parent[pos];
	}
	return true;
}
int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&r,&c);
		for (int i = 0; i < r; ++i)
		{
			scanf("%s",land[i]);
		}
		bool flag;
		row_c=0;
		for (int i = 0; i < r; ++i)
		{
			flag=true;
			for (int j = 0; j < c; ++j)
			{
				if(land[i][j]=='*' && flag)
				{
					flag=false;
					row_c++;
				}
				if(land[i][j]=='.')
				{
					flag=true;
				}
				row_mat[i][j]=row_c;
			}
		}
		col_c=row_c;
		for (int j = 0; j < c; ++j)
		{
			flag=true;
			for (int i = 0; i < r; ++i)
			{
				if(land[i][j]=='*' && flag)
				{
					flag=false;
					col_c++;
				}
				if(land[i][j]=='.')
				{
					flag=true;
				}
				col_mat[i][j]=col_c;
			}
		}
		for (int i = 0; i <= col_c+1; ++i)
		{
			for (int j = 0; j <= col_c+1; ++j)
			{
				A[i][j]=0;
			}
		}
		for (int i = 1; i <= row_c; ++i)
		{
			A[0][i]=1;
		}
		for (int i = row_c+1; i <= col_c; ++i)
		{
			A[i][col_c+1]=1;
		}
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if(land[i][j]=='*')
					A[row_mat[i][j]][col_mat[i][j]]=1;
			}
		}
		int ans=0;
		while(get_path())
		{
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}