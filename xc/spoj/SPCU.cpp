#include <cstdio>
using namespace std;
int main()
{
	int t,n,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		bool ans=true;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x>i)
				ans=false;
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}