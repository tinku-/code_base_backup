#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main()
{
	int m,n;
	int temp = 1;
	cin>>n>>m;
	char a[1000][1000]={0};
	//memset(a, '.', sizeof a);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(i%2==0)
			{
				a[i][j]='#';
			}
			else
			{
				if(temp == 1)
				{
					a[i][m-1]='#';
					temp = 1 - temp;
					j=0;break;
				}
				if(temp == 0)
				{
					a[i][0]='#';
					temp = 1 - temp;
					j=0;break;
				}
			}
		}
	for(int i=0;i<n;i++)
	{
		if(i != 0){cout<<"\n";}
		for(int j=0;j<m;j++)
			cout<<a[i][j];
	}
	return 0;
}

/*
#include<stdio.h>
int n,m,i,j;
int main(){
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(i%2==0||(i%4==3&&j==0)||(i%4==1&j==m-1))printf("#");
			else printf(".");
		}
		puts("");
	}
}
//shorter version of code................................
*/