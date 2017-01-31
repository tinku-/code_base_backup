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
#include <fstream>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;
int main()
{
	freopen("spojinp.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int A[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&A[i]);
		}
		vector <int> l_to_r(n),r_to_l(n);
		l_to_r[0]=1;
		for(int i=1;i<n;i++)
		{
			int best=-1;
			for(int j=0;j<i;j++)
			{
				if(A[j]<A[i])
				{
					if(best==-1 || l_to_r[j]>l_to_r[best])
						best=j;
				}
			}
			if(best==-1)
				l_to_r[i]=1;
			else
				l_to_r[i]=l_to_r[best]+1;
		}
		r_to_l[n-1]=1;
		for(int i=n-2;i>=0;i--)
		{
			int best=n;
			for(int j=n-1;j>i;j--)
			{
				if(A[j]<A[i])
				{
					if(best==n || r_to_l[j]>r_to_l[best])
						best=j;
				}
			}
			if(best==n)
				r_to_l[i]=1;
			else
				r_to_l[i]=r_to_l[best]+1;
		}
		int a=0,b=0;
		for(int i=0;i<n;i++)
		{
			a=max(a,l_to_r[i]);
			b=max(b,r_to_l[i]);
		}
		printf("%d\n",a+b-1);
	}
	return 0;
}