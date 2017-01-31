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
struct point
{
	long long int x,y;
};
int orientation(point a,point b,point c)
{
	//finding cross product: (c-b) X (b-a)
	//0: collinear, 1:clockwise, 2:counter-clockwise
	long long int ans=(c.x-b.x)*(b.y-a.y) - (c.y-b.y)*(b.x-a.x);
	if(ans==0)
		return 0;
	if(ans>0)
		return 1;
	//answer must be less than 0
	return 2;
}
long long int sq_dist(point a,point b)
{
	long long int ans=(a.x-b.x)*(a.x*b.x) + (a.y-b.y)*(a.y-b.y);
	return ans;
}
point p0;
bool sorter(const point &a,const point &b)
{
	int o=orientation(p0,a,b);
	if(o==0)
	{
		return sq_dist(a,p0)<sq_dist(b,p0);
	}
	if(o==1)
	{
		return false;
	}
	return true;
}
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	vector <point> A(n);
	for(int i=0;i<n;i++)
		scanf("%lld %lld",&A[i].x,&A[i].y);
	while(A.size()>2)
	{
		vector <point> left_over,hull(3);
		int least=0;
		for(int i=0;i<A.size();i++)
		{
			if(A[i].y<A[least].y || (A[i].y==A[least].y && A[i].x<A[least].x))
				least=i;
		}
		swap(A[0],A[least]);
		p0=A[0];
		sort(A.begin()+1, A.end(),sorter);
		hull[0]=A[0];
		hull[1]=A[1];
		hull[2]=A[2];
		int hull_sz=3;
		for(int i=3;i<A.size();i++)
		{
			while(orientation(hull[hull_sz-2],hull[hull_sz-1],A[i])==1)
			{
				left_over.push_back(hull.back());
				hull.pop_back();
				hull_sz--;
			}
			if(orientation(hull[hull_sz-2],hull[hull_sz-1],A[i])==0)
			{
				left_over.push_back(hull.back());
				hull.pop_back();
				hull_sz--;
			}
			hull.push_back(A[i]);
			hull_sz++;
		}
		A=left_over;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}