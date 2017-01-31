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
using namespace std;
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
const int SIZE=10000000; 
static char buff[SIZE],*p;
void r(int &n) 
 {
   while(*p<47)
     p++; 
     n=0;
     while(*p>47)
       {
       n=n*10+*p++-48;
       }
 }
int main()
{
	fread(buff,1,SIZE,stdin);
	p=buff;
	int t;
	r(t);
	while(t--)
	{
		int n,x;
		r(n);
		if(n>9)
		{
			for(int i=0;i<n;i++)
				r(x);
			printf("YES\n");
		}
		else
		{
			vector <int> A(n),counter(100,0);
			int cs=0;
			bool flag=false;
			for (int i = 0; i < n; ++i)
			{
				r(A[i]);
				cs+=A[i];
				if(counter[A[i]]==1)
					flag=true;
				else
					counter[A[i]]=1;
			}
			if(flag || cs<(1<<n))
			{
				printf("YES\n");
				continue;
			}
			vector <int> sums(901,0);
			for (int mask = 0; mask < (1<<n); ++mask)
			{
				cs=0;
				for (int i = 0; i < n; ++i)
				{
					if(mask & (1<<i))
						cs+=A[i];
				}
				if(sums[cs]==1)
				{
					flag=true;
					break;
				}
				else
				{
					sums[cs]=1;
				}
			}
			if(flag)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}