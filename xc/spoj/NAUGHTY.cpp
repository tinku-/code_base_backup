#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int n,x,y,ans=1000000;
	scanf("%d",&n);
	vector <int> A(100001,0),B(100001,0);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		A[x]++;
		A[y]++;
		B[y]++;
	}
	for(int i=0;i<=100000;i++)
	{
		if(A[i]>=(n+1)/2)
		{
			x=A[i]-B[i];
			if(x>=(n+1)/2)
			{
				ans=0;
				break;
			}
			else
			{
				x=((n+1)/2)-x;
				if(x<ans)
					ans=x;
			}
		}
	}
	if(ans==1000000)
		printf("Impossible\n");
	else
		printf("%d\n",ans);
	return 0;
}
