#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int t,n,prev,curr;
	bool ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=true;
		scanf("%d",&prev);
		for(int i=1;i<n;i++)
		{
			scanf("%d",&curr);
			if(prev>curr)
				ans=false;
			else
			{
				prev=curr-prev;
			}
		}
		if(prev!=0)
			ans=false;
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}