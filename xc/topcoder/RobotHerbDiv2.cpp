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

class RobotHerbDiv2 {
public:
	int getdist(int, vector <int>);
};

int RobotHerbDiv2::getdist(int T, vector <int> a)
{
	int dx=0,dy=0,ddir=0;
	for(int i=0;i<a.size();i++)
	{
		if(ddir==0)
		dy+=a[i];
		else if(ddir==2)
		dy-=a[i];
		else if(ddir==1)
		dx+=a[i];
		else
		dx-=a[i];
		ddir+=(a[i]%4);
		ddir%=4;
	}
	int x=dx,y=dy,dir=ddir;
	for(int i=1;i<T;i++)
	{
		if(dir==0)
		{
			x+=dx;
			y+=dy;
			
		}
		else if(dir==2)
		{
			x-=dx;
			y-=dy;
		}
		else if(dir==1)
		{
			x+=dy;
			y-=dx;
		}
		else
		{
			x-=dy;
			y+=dx;
		}
		dir+=ddir;
		dir%=4;
	}
	return (abs(x)+abs(y));	
}

double test0() {
	int p0 = 1;
	int t1[] = {1,2,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	RobotHerbDiv2 * obj = new RobotHerbDiv2();
	clock_t start = clock();
	int my_answer = obj->getdist(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	int p0 = 100;
	int t1[] = {1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	RobotHerbDiv2 * obj = new RobotHerbDiv2();
	clock_t start = clock();
	int my_answer = obj->getdist(p0, p1);
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
double test2() {
	int p0 = 5;
	int t1[] = {1,1,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	RobotHerbDiv2 * obj = new RobotHerbDiv2();
	clock_t start = clock();
	int my_answer = obj->getdist(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 10;
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
	int p0 = 100;
	int t1[] = {400000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	RobotHerbDiv2 * obj = new RobotHerbDiv2();
	clock_t start = clock();
	int my_answer = obj->getdist(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 40000000;
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
