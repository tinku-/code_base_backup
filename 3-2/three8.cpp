#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int a[64][2];
int main()
{
	int i,j;
	int d=0;
	int ct=0;


	for(i=0;i<64;i++)
	{
		for(j=0;j<2;j++)
		{
			a[i][j]=-1;
		}
	}

	printf("Enter the chess board :\n");

	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			scanf("%d",&d);

			if(d==1)
			{
				a[ct][0]=i;
				a[ct][1]=j;
				ct++;
			}
		}
	}

	int safe=1;


	for(i=0;i<ct;i++)
	{
		for(j=i+1;j<ct;j++)
		{
			if(a[i][0]==a[j][0] || a[i][1]==a[j][1] || abs(a[i][0]-a[j][0])==abs(a[i][1]-a[j][1]))
			{
				safe=0;
				goto end;
			}
		}
	}

	end:


	if(safe==0)
		printf("NO\n");
	else
		printf("YES\n");

return 0;



}