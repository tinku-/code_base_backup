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

class Cryptography {
public:
	long long encrypt(vector <int>);
};

double test0() {
	int t0[] = {1,2,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Cryptography * obj = new Cryptography();
	clock_t start = clock();
	long long my_answer = obj->encrypt(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 12LL;
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
	int t0[] = {1,3,2,1,1,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Cryptography * obj = new Cryptography();
	clock_t start = clock();
	long long my_answer = obj->encrypt(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 36LL;
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
	int t0[] = {1000,999,998,997,996,995};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Cryptography * obj = new Cryptography();
	clock_t start = clock();
	long long my_answer = obj->encrypt(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 986074810223904000LL;
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
	int t0[] = {1,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Cryptography * obj = new Cryptography();
	clock_t start = clock();
	long long my_answer = obj->encrypt(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 2LL;
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

long long Cryptography::encrypt(vector <int> numbers) 
{
	long long mm=1;
	numbers[0]++;
	for(int i=0;i<numbers.size();i++)
	mm*=numbers[i];
	numbers[0]--;
	for(int i=1;i<numbers.size();i++)
	{
		numbers[i]++;
		long long x=1;
		for(int j=0;j<numbers.size();j++)
		x*=numbers[j];
		if(x>mm)
			mm=x;
		numbers[i]--;
	}
	return mm;
}


//Powered by [KawigiEdit] 2.0!
