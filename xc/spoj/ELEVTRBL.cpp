#include <cstdio>
#include <deque>
#include <vector>
using namespace std;
struct floor
{
	int ans,no;
};
int main()
{
	int floors,curr,dest,up,down;
	scanf("%d%d%d%d%d",&floors,&curr,&dest,&up,&down);
	deque <floor> A(1);
	vector <int> visited(floors+1,0);
	floor x;
	A[0].ans=0;
	A[0].no=curr;
	visited[curr]=1;
	while(!A.empty())
	{
		if(A[0].no==dest)
			break;
		if(A[0].no+up<=floors)
		{
			if(visited[A[0].no+up]==0)
			{
				visited[A[0].no+up]=1;
				x.ans=A[0].ans+1;
				x.no=A[0].no+up;
				A.push_back(x);	
			}
		}
		if(A[0].no-down>0)
		{
			if(visited[A[0].no-down]==0)
			{
				visited[A[0].no-down]=1;
				x.ans=A[0].ans+1;
				x.no=A[0].no-down;
				A.push_back(x);	
			}
		}
		A.pop_front();
	}
	if(A.empty())
		printf("use the stairs\n");
	else
		printf("%d\n",A[0].ans);
	return 0;
}