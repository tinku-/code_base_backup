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

class DancingFoxes
{
vector <string> A;
int n;
public:
	int minimalDays(vector <string>);
	deque <int> bfs(deque <int>,int[],int[]);
};
deque <int> DancingFoxes::bfs(deque <int> que,int mark[],int dep[])
{
	int num=que.front();
	for(int i=0;i<n;i++)
	{
		if(A[num][i]=='Y')
		{
			if(mark[i]==0)
			{
				que.push_back(i);
				mark[i]=1;
				dep[i]=dep[num]+1;
			}
		}
	}
	return que;
}	
int DancingFoxes::minimalDays(vector <string> friendship)
{
	n=friendship.size();
	A=friendship;
	int markz[51]={0,0},markf[51]={0,0},depz[51]={0,0},depf[51]={0,0};
	deque <int> quez,quef;
	markz[0]=1;
	markf[1]=1;
	depz[0]=-1;
	depf[1]=-1;
	quez.push_back(0);
	quef.push_back(1);
	while(quez.size()!=0)
	{
		quez=bfs(quez,markz,depz);
		quez.pop_front();
	}
	while(quef.size()!=0)
	{
		quef=bfs(quef,markf,depf);
		quef.pop_front();
	}
	int ans=100000000;
	for(int i=0;i<n;i++)
	{
		if((markz[i]==1)&&(markf[i]==1))
		{
			ans=min(ans,depz[i]+depf[i]+1);
		}
	}
	if(ans==100000000)
	return -1;
	else
	return ans;
}


double test0() {
	string t0[] = {"NNY",
 "NNY",
 "YYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	DancingFoxes * obj = new DancingFoxes();
	clock_t start = clock();
	int my_answer = obj->minimalDays(p0);
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
	string t0[] = {"NNNNN",
 "NNYYY",
 "NYNYY",
 "NYYNY",
 "NYYYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	DancingFoxes * obj = new DancingFoxes();
	clock_t start = clock();
	int my_answer = obj->minimalDays(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
	string t0[] = {"NNYYNN",
 "NNNNYY",
 "YNNNYN",
 "YNNNNY",
 "NYYNNN",
 "NYNYNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	DancingFoxes * obj = new DancingFoxes();
	clock_t start = clock();
	int my_answer = obj->minimalDays(p0);
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
double test3() {
	string t0[] = {"NNYNNNNYN",
 "NNNNYNYNN",
 "YNNYNYNNN",
 "NNYNYNYYN",
 "NYNYNNNNY",
 "NNYNNNYNN",
 "NYNYNYNNN",
 "YNNYNNNNY",
 "NNNNYNNYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	DancingFoxes * obj = new DancingFoxes();
	clock_t start = clock();
	int my_answer = obj->minimalDays(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
double test4() {
	string t0[] = {"NY",
 "YN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	DancingFoxes * obj = new DancingFoxes();
	clock_t start = clock();
	int my_answer = obj->minimalDays(p0);
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
