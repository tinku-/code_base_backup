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
		vector <int> A(n,1),ans(n,-1);
		for(int i=0;i<n;i++)
		{
			int index=i+1;
			while(index%2==0)
			{
				A[i]*=2;
				index/=2;
			}
		}
		int curr=0,curr_sum,j_sum,tot_sum=n;
		for(int i=1;i<=n;i++)
		{
			int low=0,high=n-1,mid,j,temp;
			//find curr_sum
			curr_sum=0;
			temp=curr+1;
			while(temp>0)
			{
				curr_sum+=A[temp-1];
				temp-=temp & (temp*-1);
			}
			while(low<high)
			{
				mid=(low+high)/2;
				j=(curr+mid)%n;
				//find j_sum
				j_sum=0;
				temp=j+1;
				while(temp>0)
				{
					j_sum+=A[temp-1];
					temp-=temp & (temp*-1);
				}
				//check what the difference is
				if(j<curr)
				{
					j_sum+=(tot_sum-curr_sum);
				}
				else
				{
					j_sum-=curr_sum;
				}
				//modify high or low
				if(j_sum<(i%tot_sum))
					low=mid+1;
				else
					high=mid;
			}
			//printf("\n%d %d %d\n",curr,high,curr_sum);
			curr+=high;
			curr%=n;
			ans[curr]=i;
			tot_sum--;
			//update A;
			temp=curr+1;
			while(temp<=n)
			{
				A[temp-1]--;
				temp+=temp & (temp*-1);
			}
			//update curr
			while(ans[curr]!=-1 && i<n)
			{
				curr++;
				curr%=n;
			}
		}
		for(int i=0;i<n;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}