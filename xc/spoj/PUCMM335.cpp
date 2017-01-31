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
int main()
{
	freopen("spojinp.txt","r",stdin);
	int dr[]={1,-1,0,0},dc[]={0,0,1,-1};
	char board[8][9];
	for (int i = 0; i < 8; ++i)
	{
		scanf("%s",board[i]);
	}
	int n,ans=-1,danny_r,danny_c,princess_r,princess_c;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if(board[i][j]=='$')
			{
				danny_r=i;
				danny_c=j;
			}
			if(board[i][j]=='?')
			{
				princess_r=i;
				princess_c=j;
			}
		}
	}
	scanf("%d",&n);
	if(n==0)
	{
		vector <vector <int> > b_board(8,vector <int> (8,-1));
		queue <pair<int,int> > bfs;
		bfs.push(pair<int,int>(danny_r,danny_c));
		b_board[danny_r][danny_c]=0;
		while(!bfs.empty())
		{
			pair <int,int> top=bfs.front();
			bfs.pop();
			int x=top.first,y=top.second;
			if(board[x][y]=='?')
				break;
			for (int i = 0; i < 4; ++i)
			{
				if(x+dr[i]<0 || x+dr[i]>7 || y+dc[i]<0 || y+dc[i]>7 || b_board[x+dr[i]][y+dc[i]]!=-1 || board[x+dr[i]][y+dc[i]]=='#')
					continue;
				b_board[x+dr[i]][y+dc[i]]=b_board[x][y]+1;
				bfs.push(pair<int,int> (x+dr[i],y+dc[i]));
			}
		}
		ans=max(ans,b_board[princess_r][princess_c]);
	}
	else
	{
		for (int king_count = 0; king_count < n; ++king_count)
		{
			int kx,ky;
			scanf("%d %d",&kx,&ky);
			board[kx][ky]='#';
			vector <vector <int> > b_board(8,vector <int> (8,-1));
			queue <pair<int,int> > bfs;
			bfs.push(pair<int,int>(danny_r,danny_c));
			b_board[danny_r][danny_c]=0;
			while(!bfs.empty())
			{
				pair <int,int> top=bfs.front();
				bfs.pop();
				int x=top.first,y=top.second;
				if(board[x][y]=='?')
					break;
				for (int i = 0; i < 4; ++i)
				{
					if(x+dr[i]<0 || x+dr[i]>7 || y+dc[i]<0 || y+dc[i]>7 || b_board[x+dr[i]][y+dc[i]]!=-1 || board[x+dr[i]][y+dc[i]]=='#')
						continue;
					b_board[x+dr[i]][y+dc[i]]=b_board[x][y]+1;
					bfs.push(pair<int,int> (x+dr[i],y+dc[i]));
				}
			}
			ans=max(ans,b_board[princess_r][princess_c]);
			board[kx][ky]='.';
		}
	}
	printf("%d\n", ans);
	return 0;
}