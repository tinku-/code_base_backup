#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,m;
vector <vector <char> > A;
bool check(int i,int j)
{
	if(i<0)
	return false;
	if(j<0)
	return false;
	if(i>n+1)
	return false;
	if(j>m+1)
	return false;
	if(A[i][j]=='#')
	return false;
	return true;
}
void spreader(int &wolf_count,int &sheep_count,int i,int j)
{
	if(A[i][j]=='k')
		sheep_count++;
	if(A[i][j]=='v')
		wolf_count++;
	A[i][j]='#';
	if(check(i-1,j))
		spreader(wolf_count,sheep_count,i-1,j);
	if(check(i+1,j))
		spreader(wolf_count,sheep_count,i+1,j);
	if(check(i,j-1))
		spreader(wolf_count,sheep_count,i,j-1);
	if(check(i,j+1))
		spreader(wolf_count,sheep_count,i,j+1);
}
int main()
{
	cin>>n>>m;
	vector <char> x(m+2,'.');
	vector <vector <char> > y(n+2,x);
	A=y;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cin>>A[i][j];
	}
	int wolf_count=0,sheep_count=0;
	int w,s;
	spreader(wolf_count,sheep_count,0,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(A[i][j]!='#')
			{
				w=0;
				s=0;
				spreader(w,s,i,j);
				if(s>w)
					sheep_count+=s;
				else
					wolf_count+=w;
			}
		}
	}
	cout<<sheep_count<<" "<<wolf_count;
	return 0;
}
