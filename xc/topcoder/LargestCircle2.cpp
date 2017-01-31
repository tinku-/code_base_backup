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
vector <string> A;
bool isposs(int i,int j,int rad)
{
	if(rad==0)
	return true;
	else
	return false;
}
int evaluate(int i,int j)
{
	int maxr=i+1,n=A.size();
	maxr=min(maxr,j);
	maxr=min(maxr,n-i);
	maxr=min(maxr,n+1-j);
	for(int rad=maxr;rad>=0;rad--)
	{
		if(isposs(i,j,rad))
		return rad;
	}
}
class LargestCircle2 {
public:
	int radius(vector <string>);
};

int LargestCircle2::radius(vector <string> grid)
{
	int ans=0;
	A=grid;
	for(int i=0;i<grid.size();i++)
	{
		for(int j=0;j<grid[0].size();j++)
		{
			ans=max(ans,evaluate(i,j));
		}
	}
	return ans;
}


double test0() {
	string t0[] = {"####",
 "#..#",
 "#..#",
 "####"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LargestCircle2 * obj = new LargestCircle2();
	clock_t start = clock();
	int my_answer = obj->radius(p0);
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
	string t0[] = {"############",
 "###......###",
 "##.######.##",
 "#.########.#",
 "#.##..####.#",
 "#.##..####.#",
 "#.########.#",
 "#.########.#",
 "#.########.#",
 "##.######.##",
 "###......###",
 "############"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LargestCircle2 * obj = new LargestCircle2();
	clock_t start = clock();
	int my_answer = obj->radius(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
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
	string t0[] = {".........."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LargestCircle2 * obj = new LargestCircle2();
	clock_t start = clock();
	int my_answer = obj->radius(p0);
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
	string t0[] = {"#######",
 "#######",
 "#######",
 "#######",
 "#######"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LargestCircle2 * obj = new LargestCircle2();
	clock_t start = clock();
	int my_answer = obj->radius(p0);
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
double test4() {
	string t0[] = {"#####.......",
 "#####.......",
 "#####.......",
 "............",
 "............",
 "............",
 "............",
 "............",
 "............",
 "............"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LargestCircle2 * obj = new LargestCircle2();
	clock_t start = clock();
	int my_answer = obj->radius(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
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
double test5() {
	string t0[] = {"#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
 "...#...#...#...#...#...#...#...#...#...#...#...#..",
 "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
 ".#...#...#...#...#...#...#...#...#...#...#...#...#",
 "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
 "...#...#...#...#...#...#...#...#...#...#...#...#..",
 "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
 ".#...#...#...#...#...#...#...#...#...#...#...#...#",
 "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
 "...#...#...#...#...#...#...#...#...#...#...#...#.#",
 "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LargestCircle2 * obj = new LargestCircle2();
	clock_t start = clock();
	int my_answer = obj->radius(p0);
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
double test6() {
	string t0[] = {".........................#........................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 ".................................................."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LargestCircle2 * obj = new LargestCircle2();
	clock_t start = clock();
	int my_answer = obj->radius(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 24;
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	time = test6();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
