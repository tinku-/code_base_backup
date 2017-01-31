#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main()
{
	int m,n;
	int temp = 1;
	cin>>n>>m;
	char a[n][m];
	memset(a, '.', sizeof a);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(i%2==0){a[i][j]='#';}
			else
				if(temp = 1)
				{
					a[i][m-1]='#';
					temp = 1 - temp;
					i++;j=0;
				}
				else 
				{
					a[i][0]='#';
					temp = 1 - temp;
					i++;j=0;
				}
		}
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		for(int j=0;j<m;j++)
			cout<<a[i][j];
	}
	return 0;
}