#include <cstdio>
using namespace std;
int main()
{
	int A[22];
	A[0]=1;
	A[1]=1;
	for(int i=2;i<22;i++)
		A[i]=A[i-1]*2;
	int n,tn,ans,last_level,x,fans;
	scanf("%d",&n);
	while(n!=0)
	{
		tn=n;
		for(last_level=1;A[last_level]<tn;last_level++)
			tn-=A[last_level];
		ans=tn+(A[last_level-1]-((tn+1)/2));
		for(int i=0;i<n-ans;i++)
			scanf("%d",&x);
		fans=0;
		for(int i=0;i<ans;i++)
		{
			scanf("%d",&x);
			fans+=x;
		}
		printf("%d\n",fans);
		scanf("%d",&n);
	}
	return 0;
}