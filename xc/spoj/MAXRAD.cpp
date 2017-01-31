#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct point
{
	int x,y;
};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector <point> A(n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&A[i].x,&A[i].y);
		double most=0;
		for(int i=0;i<n;i++)
		{
			double x,least=100000000;
			for(int j=0;j<n;j++)
			{
				if(i==j)
					continue;
				x=sqrt(pow(A[i].x-A[j].x,2)+pow(A[i].y-A[j].y,2));
				if(x<least)
					least=x;
			}
			if(least<1.999999)
			{
				most=-1;
				break;
			}
			if(least>most)
				most=least;
		}
		if(most<0)
			printf("-1.000000\n");
		else
			printf("%f\n",most-1);
	}
	return 0;
}