#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int t,n,x,count;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		count=0;
		vector <int> A((n+1)/2,0);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x>((n-1)/2))
				x=(n-1)-x;
			if(x>=0)
			{
				A[x]++;
				if(A[x]==2)
					count++;
			}
		}
		if(n%2==0)
		{
			if(count==n/2)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
		{
			if(count==n/2&&A[n/2]==1)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}