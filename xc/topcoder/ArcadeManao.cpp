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

using namespace std;
struct platform
{
	int n,l,r,h;
};
bool sorter(const platform &x,const platform &y)
{
	return x.n<y.n;
}
class ArcadeManao {
public:
	int shortestLadder(vector <string>, int, int);
};
int ArcadeManao::shortestLadder(vector <string> level, int coinRow, int coinCol)
{
	int c=1;
	level[coinRow-1][coinCol-1]='O';
	platform x;
	vector <platform> A;
	vector <int> B;
	vector <int> mark,pq;
	vector <vector <int> > grid;
	for(int i=0;i<level.size();i++)
	{
		for(int j=0;j<level[i].size();j++)
		{
			if((level[i][j]=='X')||(level[i][j]=='O'))
			{
				x.h=i+1;
				x.l=j+1;
				x.n=1;
				while(j<level[i].size())
				{
					if(level[i][j]=='O')
					x.n=0;
					if(level[i][j]=='.')
					break;
					j++;
				}
				x.r=j;
				if(x.n!=0)
				{
					x.n=c;
					c++;
				}
				A.push_back(x);
			}
		}
	}
	//cout<<"knv";
	sort(A.begin(),A.end(),sorter);
	if(A[0].h==level.size())
	return 0;
	for(int i=0;i<A.size();i++)
	B.push_back(0);
	for(int i=0;i<A.size();i++)
	grid.push_back(B);
	for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<A.size();j++)
		{
			if(i==j)
			continue;
			if(A[i].h==A[j].h)
			continue;
			if((A[i].l<=A[j].l)&&(A[i].r>=A[j].r))
			{
				grid[i][j]=max(A[i].h-A[j].h,A[j].h-A[i].h);
				grid[j][i]=max(A[i].h-A[j].h,A[j].h-A[i].h);
				continue;
			}
			if((A[j].l<=A[i].l)&&(A[j].r>=A[i].r))
			{
				grid[i][j]=max(A[i].h-A[j].h,A[j].h-A[i].h);
				grid[j][i]=max(A[i].h-A[j].h,A[j].h-A[i].h);
				continue;
			}
		}
	}
	for(int i=0;i<A.size();i++)
	{
		mark.push_back(0);
		pq.push_back(100000000);
	}
	pq[pq.size()-1]=0;
	while(mark[0]==0)
	{
		int least=0;
		for(int i=0;i<A.size();i++)
		{
			if((mark[i]==0)&&(pq[i]<pq[least]))
			least=i;
		}
		mark[least]=1;
		for(int i=0;i<grid[least].size();i++)
		{
			if(grid[least][i]!=0)
			pq[i]=min(pq[i],max(pq[least],grid[least][i]));
		}
	}
	return pq[0];
}


double test0() {
	string t0[] = {"XXXX....",
 "...X.XXX",
 "XXX..X..",
 "......X.",
 "XXXXXXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	int p2 = 4;
	ArcadeManao * obj = new ArcadeManao();
	clock_t start = clock();
	int my_answer = obj->shortestLadder(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"XXXX",
 "...X",
 "XXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 1;
	ArcadeManao * obj = new ArcadeManao();
	clock_t start = clock();
	int my_answer = obj->shortestLadder(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"..X..",
 ".X.X.",
 "X...X",
 ".X.X.",
 "..X..",
 "XXXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 3;
	ArcadeManao * obj = new ArcadeManao();
	clock_t start = clock();
	int my_answer = obj->shortestLadder(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 1;
	ArcadeManao * obj = new ArcadeManao();
	clock_t start = clock();
	int my_answer = obj->shortestLadder(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"XXXXXXXXXX",
 "...X......",
 "XXX.......",
 "X.....XXXX",
 "..XXXXX..X",
 ".........X",
 ".........X",
 "XXXXXXXXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 1;
	ArcadeManao * obj = new ArcadeManao();
	clock_t start = clock();
	int my_answer = obj->shortestLadder(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
