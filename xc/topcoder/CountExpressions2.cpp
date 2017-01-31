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
int A[7];
int val,ans=0,a,b;
int evaluator()
{
	int tans=A[0];
	for(int i=2;i<7;i+=2)
	{
		if(A[i-1]==1)
		tans+=A[i];
		else if(A[i-1]==2)
		tans-=A[i];
		else
		tans*=A[i];
	}
	return tans;
}
void process(int depth)
{
	if(depth==7)
	{
		int ac=0,bc=0;
		if(A[0]==a)
		ac++;
		else
		bc++;
		if(A[2]==a)
		ac++;
		else
		bc++;
		if(A[4]==a)
		ac++;
		else
		bc++;
		if(A[6]==a)
		ac++;
		else
		bc++;
		if(ac!=2)
		return;
		if(evaluator()==val)
		{
			ans++;
		}
		return;
	}
	if(depth%2==0)
	{
		A[depth]=a;
		process(depth+1);
		A[depth]=b;
		process(depth+1);
	}
	else
	{
		A[depth]=1;
		process(depth+1);
		A[depth]=2;
		process(depth+1);
		A[depth]=3;
		process(depth+1);
	}
}
class CountExpressions2
{
public:
	int calcExpressions(int, int, int);
};

int CountExpressions2::calcExpressions(int x, int y, int v)
{
	val=v;
	ans=0;
	a=x;
	b=y;
	process(0);
	return ans;
}


double test0() {
	int p0 = 7;
	int p1 = 8;
	int p2 = 16;
	CountExpressions2 * obj = new CountExpressions2();
	clock_t start = clock();
	int my_answer = obj->calcExpressions(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 9;
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
	int p0 = 3;
	int p1 = 5;
	int p2 = 7;
	CountExpressions2 * obj = new CountExpressions2();
	clock_t start = clock();
	int my_answer = obj->calcExpressions(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
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
	int p0 = 99;
	int p1 = 100;
	int p2 = 98010000;
	CountExpressions2 * obj = new CountExpressions2();
	clock_t start = clock();
	int my_answer = obj->calcExpressions(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 6;
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
	int p0 = -99;
	int p1 = 42;
	int p2 = -1764;
	CountExpressions2 * obj = new CountExpressions2();
	clock_t start = clock();
	int my_answer = obj->calcExpressions(p0, p1, p2);
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
double test4() {
	int p0 = 100;
	int p1 = -100;
	int p2 = -100000000;
	CountExpressions2 * obj = new CountExpressions2();
	clock_t start = clock();
	int my_answer = obj->calcExpressions(p0, p1, p2);
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
double test5() {
	int p0 = 1;
	int p1 = 2;
	int p2 = 5;
	CountExpressions2 * obj = new CountExpressions2();
	clock_t start = clock();
	int my_answer = obj->calcExpressions(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 17;
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
