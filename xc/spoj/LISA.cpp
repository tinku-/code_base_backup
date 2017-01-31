#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;
int main()
{
	freopen("spojinp.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char A[105];
		scanf("%s",A);
		int n=0;
		for (int i = 0; A[i]!='\0'; ++i)
		{
			if(A[i]>='0'&&A[i]<='9')
				n++;
		}
		long long int dp1[n][n],dp2[n][n];
		for (int i = 0; i < n; ++i)
		{
			dp1[i][i]=A[2*i]-'0';
			dp2[i][i]=dp1[i][i];
		}
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 0; j+i-1< n; ++j)
			{
				dp1[j][j+i-1]=0;
				for (int k = j; k < j+i-1; ++k)
				{
					if(A[(2*k)+1]=='+')
						dp1[j][i+j-1]=max(dp1[j][i+j-1],dp1[j][k]+dp1[k+1][i+j-1]);
					else
						dp1[j][i+j-1]=max(dp1[j][i+j-1],dp1[j][k]*dp1[k+1][i+j-1]);
				}
			}
		}
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 0; j+i-1< n; ++j)
			{
				dp2[j][j+i-1]=dp1[0][n-1];
				for (int k = j; k < j+i-1; ++k)
				{
					if(A[(2*k)+1]=='+')
						dp2[j][i+j-1]=min(dp2[j][i+j-1],dp2[j][k]+dp2[k+1][i+j-1]);
					else
						dp2[j][i+j-1]=min(dp2[j][i+j-1],dp2[j][k]*dp2[k+1][i+j-1]);
				}
			}
		}
		printf("%lld %lld\n", dp1[0][n-1],dp2[0][n-1]);
	}
	return 0;
}