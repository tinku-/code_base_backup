#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int s;
	scanf("%d",&s);
	vector <int> Q(s),N(s);
	for(int i=0;i<s;i++)
	{
		scanf("%d",&Q[i]);
	}
	for(int i=0;i<s;i++)
	{
		scanf("%d",&N[i]);
	}
	sort(Q.begin(), Q.end());
	sort(N.begin(), N.end());
	int N_low=0,N_high=s-1,Q_pos=s-1,ans=0;
	while(Q_pos>=0)
	{
		if(Q[Q_pos]>=N[N_high])
		{
			Q_pos--;
			N_low++;
		}
		else
		{
			Q_pos--;
			N_high--;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}