#include <cstdio>
using namespace std;
int main()
{
	int t,n,counter,x;
	bool ans;
	scanf("%d",&t);
	while(t--)
	{
		ans=true;
		counter=1;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x>counter)
				ans=false;
			else
			{
				counter-=x;
				counter*=2;
			}
		}
		if(counter!=0)
			ans=false;
		if(ans)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}