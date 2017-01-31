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

class TheTilesDivTwo {
public:
	int find(vector <string>);
};

int TheTilesDivTwo::find(vector <string> A)
{
	int ans=0;
	if(A.size()==1)
	return ans;
	for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<A[i].size();j++)
		{
			if((i+j)%2==1)
			continue;
			if(A[i][j]=='X')
			continue;
			if(i==0)
			{
				if(A[i+1][j]!='.')
				continue;
			}
			else if(i==A.size()-1)
			{
				if(A[i-1][j]!='.')
				continue;
			}	
			else
			{
				if((A[i+1][j]!='.')&&(A[i-1][j]!='.'))
				continue;
			}
			if(j==0)
			{
				if(A[i][j+1]!='.')
				continue;
			}
			else if(j==A[i].size()-1)
			{
				if(A[i][j-1]!='.')
				continue;
			}	
			else
			{
				if((A[i][j+1]!='.')&&(A[i][j-1]!='.'))
				continue;
			}
			ans++;
			if(i==0)
			A[i+1][j]='X';
			else if(i==A.size()-1)
			A[i-1][j]='X';
			else
			{
				if(A[i-1][j]=='.')
				A[i-1][j]='X';
				else
				A[i+1][j]='X';
			}
			if(j==0)
			A[i][j+1]='X';
			else if(j==A.size()-1)
			A[i][j-1]='X';
			else
			{
				if(A[i][j-1]=='.')
				A[i][j-1]='X';
				else
				A[i][j+1]='X';
			}
		}
	}
	return ans;
}


double test0() {
	string t0[] = {"X.X",
 "...",
 "X.X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheTilesDivTwo * obj = new TheTilesDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"...",
 "...",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheTilesDivTwo * obj = new TheTilesDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"......X.X.XXX.X.XX."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheTilesDivTwo * obj = new TheTilesDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"X.....XXX.XX..XXXXXXXXX...X.XX.XX....X",
 ".XXXX..X..XXXXXXXX....XX.X.X.X.....XXX",
 "....XX....X.XX..X.X...XX.X..XXXXXXX..X",
 "XX.XXXXX.X.X..X..XX.XXX..XX...XXX.X..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheTilesDivTwo * obj = new TheTilesDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 13;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
