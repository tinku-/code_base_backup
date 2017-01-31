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
int process(string a,string b)
{
	int ans=0,as=a.size(),bs=b.size();
	for(ans=0;ans<min(as,bs);ans++)
	{
		if(a[ans]!=b[ans])
		break;
	}
	return as-ans;
}
class UndoHistory {
public:
	int minPresses(vector <string>);
};

int UndoHistory::minPresses(vector <string> lines)
{
	int ans=lines[0].size()+1;
	for(int i=1;i<lines.size();i++)
	{
		int best=lines[i].size()+2;
		for(int j=0;j<i;j++)
		{
			if(j==i-1)
			{
				if(process(lines[j],lines[i])==0)
				best=min(best,process(lines[i],lines[j]));
				else
				best=min(best,process(lines[i],lines[j])+2);
			}
			else
			{
				best=min(best,process(lines[i],lines[j])+2);
			}
		}
		ans+=(best+1);
	}
	return ans;
}


double test0() {
	string t0[] = {"tomorrow", "topcoder"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	UndoHistory * obj = new UndoHistory();
	clock_t start = clock();
	int my_answer = obj->minPresses(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 18;
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
	string t0[] = {"a","b"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	UndoHistory * obj = new UndoHistory();
	clock_t start = clock();
	int my_answer = obj->minPresses(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
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
	string t0[] = {"a", "ab", "abac", "abacus" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	UndoHistory * obj = new UndoHistory();
	clock_t start = clock();
	int my_answer = obj->minPresses(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 10;
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
	string t0[] = {"pyramid", "sphinx", "sphere", "python", "serpent"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	UndoHistory * obj = new UndoHistory();
	clock_t start = clock();
	int my_answer = obj->minPresses(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 39;
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
	string t0[] = {"ba","a","a","b","ba"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	UndoHistory * obj = new UndoHistory();
	clock_t start = clock();
	int my_answer = obj->minPresses(p0);
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
