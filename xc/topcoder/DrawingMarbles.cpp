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
class DrawingMarbles {
public:
	double sameColor(vector <int>, int);
};

double DrawingMarbles::sameColor(vector <int> colors, int n)
{
	double ans=0;
	int sum=0;
	for(int i=0;i<colors.size();i++)
	{
		sum+=colors[i];
		if(colors[i]<n)
		continue;
		double x=1;
		for(int j=0;j<n;j++)
		x*=colors[i]-j;
		ans+=x;
	}
	for(int i=0;i<n;i++)
	ans/=(sum-i);
	return ans;
}

double test0() {
	int t0[] = { 13 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 8;
	DrawingMarbles * obj = new DrawingMarbles();
	clock_t start = clock();
	double my_answer = obj->sameColor(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 1.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = { 5, 7 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	DrawingMarbles * obj = new DrawingMarbles();
	clock_t start = clock();
	double my_answer = obj->sameColor(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 1.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = { 5, 6, 7 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	DrawingMarbles * obj = new DrawingMarbles();
	clock_t start = clock();
	double my_answer = obj->sameColor(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.3006535947712418;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = { 12, 2, 34, 13, 17 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 4;
	DrawingMarbles * obj = new DrawingMarbles();
	clock_t start = clock();
	double my_answer = obj->sameColor(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.035028830818304504;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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
