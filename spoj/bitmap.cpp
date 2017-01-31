#include <bits/stdc++.h>
const int INF = 5000000;
using namespace std;
int arr[200][200],vis[200][200],dist[200][200];
queue < pair<int, int> > q;
pair<int, int> temp;

int pq(int i,int j)
{
	if(i>=0 && j>=0 && vis[i][j] == 0)
		{
			vis[i][j] = 1;
			return 1;
		}
		return 0;
}
int min4(int e,int f,int g,int h)
{
	return min(e,min(f,min(g,h)));
}
int main()
{
	string s;
	int n,m,x,y;
	int t;cin>>t;
	while(t--)
	{
		for(int i=0;i<200;i++)
			for(int j=0;j<200;j++)
			{
				if(i == 0 || j == 0)
					vis[i][j] = 1;
				else
					vis[i][j] = 0;
				dist[i][j] = INF;
				arr[i][j] = 0;
			}
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			for(int j=0;j<s.size();j++)
			{
				arr[i][j+1] = s[j] - '0';
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(arr[i][j] == 1)
				{
					temp.first = i;
					temp.second = j;
					q.push(temp);
					vis[i][j] = 1;
				}
			}
		while(!q.empty())
		{		
			temp = q.front();
			x = temp.first;
			y = temp.second;
			if(pq(x-1,y))q.push(make_pair(x-1,y));
			if(pq(x,y-1))q.push(make_pair(x,y-1));
			if(pq(x,y+1))q.push(make_pair(x,y+1));
			if(pq(x+1,y))q.push(make_pair(x+1,y));
			if(arr[x][y] == 1)
				dist[x][y] = 0;
			else
				dist[x][y] = 1 + min4(dist[x-1][y],dist[x+1][y],dist[x][y-1],dist[x][y+1]);
			q.pop();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<dist[i][j]<<" ";
			cout<<endl;
		}

	}
}


/*
3 4
0001
0011
0110
1
4 6
100001
100001
100001
100001
*/