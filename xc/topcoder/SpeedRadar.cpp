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

class SpeedRadar {
public:
	double averageSpeed(int, int, vector <int>);
};

double SpeedRadar::averageSpeed(int minLimit, int maxLimit, vector <int> readings)
{
	int n=readings.size(),corr=0,corn=0,faul=0;
	double x=0;
	for(int i=0;i<n;i++)
	{
		if((readings[i]>maxLimit)||(readings[i]<minLimit))
		faul++;
		else
		{
			corr+=readings[i];
			corn++;
		}
		x=(faul*1.0)/n;
		if(x>0.1)
		break;
	}
	if(x>0.1)
	return 0;
	else
	{
		x=(corr*1.0)/corn;
		return x;
	}
}


double test0() {
	int p0 = 1;
	int p1 = 50;
	int t2[] = {45, 40, 50};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	SpeedRadar * obj = new SpeedRadar();
	clock_t start = clock();
	double my_answer = obj->averageSpeed(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 45.0;
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
	int p0 = 1;
	int p1 = 50;
	int t2[] = {42,43,44,45,46,47,48,49,50,51};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	SpeedRadar * obj = new SpeedRadar();
	clock_t start = clock();
	double my_answer = obj->averageSpeed(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 46.0;
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
	int p0 = 1;
	int p1 = 50;
	int t2[] = {42,46,48,50,52};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	SpeedRadar * obj = new SpeedRadar();
	clock_t start = clock();
	double my_answer = obj->averageSpeed(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.0;
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
	int p0 = 20;
	int p1 = 60;
	int t2[] = {25,45,45,43,24,9,51,55,60,34,61,23,40,40,47,49,33,23,47,54,54};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	SpeedRadar * obj = new SpeedRadar();
	clock_t start = clock();
	double my_answer = obj->averageSpeed(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 41.68421052631579;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
