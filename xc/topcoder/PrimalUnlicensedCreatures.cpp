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

class PrimalUnlicensedCreatures {
public:
	int maxWins(int, vector <int>);
};

int PrimalUnlicensedCreatures::maxWins(int init, vector <int> grezPower)
{
	int ans=0;
	sort(grezPower.begin(),grezPower.end());
	while(ans<grezPower.size())
	{
		if(init>grezPower[ans])
		{
			init+=grezPower[ans]/2;
			ans++;
		}
		else
		{
			break;
		}
	}
	return ans;
}


double test0() {
	int p0 = 31;
	int t1[] = {10, 20, 30};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PrimalUnlicensedCreatures * obj = new PrimalUnlicensedCreatures();
	clock_t start = clock();
	int my_answer = obj->maxWins(p0, p1);
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
double test1() {
	int p0 = 20;
	int t1[] = {24, 5, 6, 38};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PrimalUnlicensedCreatures * obj = new PrimalUnlicensedCreatures();
	clock_t start = clock();
	int my_answer = obj->maxWins(p0, p1);
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
	int p0 = 20;
	int t1[] = {3, 3, 3, 3, 3, 1, 25 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PrimalUnlicensedCreatures * obj = new PrimalUnlicensedCreatures();
	clock_t start = clock();
	int my_answer = obj->maxWins(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
	int p0 = 4;
	int t1[] = {3, 13, 6, 4, 9};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PrimalUnlicensedCreatures * obj = new PrimalUnlicensedCreatures();
	clock_t start = clock();
	int my_answer = obj->maxWins(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
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
double test4() {
	int p0 = 7;
	int t1[] = {7, 8, 9, 10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PrimalUnlicensedCreatures * obj = new PrimalUnlicensedCreatures();
	clock_t start = clock();
	int my_answer = obj->maxWins(p0, p1);
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
