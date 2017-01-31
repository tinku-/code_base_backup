#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		scanf("%d %d",&n,&k);
		vector <int> A(n);
		for(int i=0;i<n;i++)
			scanf("%d",&A[i]);
		int pos,ops=0;
		for(pos=0;pos<n&&ops<k;pos++)
		{
			if(A[pos]<0)
			{
				A[pos]*=-1;
				ops++;
			}
			else
				break;
		}
		sort(A.begin(), A.end());
		if(ops<k)
		{
			for(int i=1;i<=(k-ops);i++)
				A[0]*=-1;
		}
		for(int i=0;i<n;i++)
			ans+=A[i];
		printf("%d\n",ans);
	}
	return 0;
}