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

class Containers {
public:
	int wastedSpace(vector <int>, vector <int>);
};

int Containers::wastedSpace(vector <int> containers, vector <int> packages)
{
	int ans=0;
	while(packages.size()!=0)
	{
		if(containers[0]<packages[0])
		{
			ans+=containers[0];
			containers.erase(containers.begin());
		}
		else
		{
			containers[0]-=packages[0];
			packages.erase(packages.begin());
		}
	}
	for(int i=0;i<containers.size();i++)
	ans+=containers[i];
	return ans;
}


double test0() {
	int t0[] = { 5, 5, 5 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 5, 5, 5 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Containers * obj = new Containers();
	clock_t start = clock();
	int my_answer = obj->wastedSpace(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
	int t0[] = { 5, 6, 7 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 5, 5, 5 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Containers * obj = new Containers();
	clock_t start = clock();
	int my_answer = obj->wastedSpace(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	int t0[] = { 2, 3, 5 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 3 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Containers * obj = new Containers();
	clock_t start = clock();
	int my_answer = obj->wastedSpace(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 7;
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
	int t0[] = { 3, 4, 5, 6 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 3, 3, 3, 3, 3 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Containers * obj = new Containers();
	clock_t start = clock();
	int my_answer = obj->wastedSpace(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
