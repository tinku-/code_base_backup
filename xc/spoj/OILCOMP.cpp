#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namspace std;
int main()
{
	int t,A[20][20],B[20][20];
	scanf("%d",&t);
	while(t--)
	{
		int w,h;
		scanf("%d%d",&w,&h);
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
				scanf("%d",&A[i][j]);
		}
		B[0][0]=A[0][0];
		if(h>1)
			B[1][0]=A[1][0];
		if(w>1)
			B[0][1]=A[0][1];
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				if(i==0&&j==0)
					continue;
				if(i==0&&j==1)
					continue;
				if(i==1&&j==0)
					continue;
				
			}
		}
	}
}