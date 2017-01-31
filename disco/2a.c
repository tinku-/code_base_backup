#include <stdio.h>
int adj[201][201];
int colour[201];
int queue[201], dist[201][201];
int v;
int i,j, k;

#define max(a, b) a>b?a:b
#define min(a, b) a>b?b:a

void ridam()
{
	for(k=0 ; k<v ; k++){
		for(i=0 ; i<v ; i++)
			colour[i] = -1;
		int start=0,end=0,j, cnt = 1;
		queue[end] = k;
		end++;
		colour[k]=1;
		while(cnt)
		{
			i = queue[start];
			start++;
			cnt--;
			for(j=0;j<v;j++)
			{
				if(adj[i][j]==1)
				{
					if(colour[j]==-1)
					{
						colour[j] = 1;
						queue[end]=j;
						dist[k][j] = dist[k][i] + 1;
						end++;
						cnt++;
					}
				}
			}
		}
	}
}

int main()
{
	int x, y, temp;
	for(i=0;i<201;i++)
		for(j=0;j<201;j++)
			adj[i][j]=0;
	for(i=0;i<201;i++)
		colour[i]=-1;
	int e,v1,v2;
	scanf("%d %d",&v,&e);
	for(i=0;i<e;i++)
	{
		scanf("%d %d",&v1,&v2);
		adj[v1][v2]=1;
		adj[v2][v1]=1;
	}
	ridam();

	x = 0, y = 200;

	for(i=0 ; i<v ; i++){
		temp = 0;
		for(j=0 ; j<v ; j++){
			temp = max(temp, dist[i][j]);
		}
		x = max(x, temp);
		y = min(y, temp);
	}

	printf("%d %d", y, x);

	return 0;
}