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

class Crossings {
public:
	vector <int> getOut(vector <int>, vector <int>);
};

vector <int> Crossings::getOut(vector <int> positions, vector <int> angles)
{
	vector <int> A;
	for(int i=0;i<angles.size();i++)
	A.push_back(1);
	for(int i=0;i<angles.size();i++)
	{
		for(int j=0;j<angles.size();j++)
		{
			if(i==j)
			continue;
			if((j<i)&&(angles[j]>=angles[i]))
			continue;
			if((j>i)&&(angles[j]<=angles[i]))
			continue;
			int di,dj;
			di=max(90-angles[i],angles[i]-90);
			dj=max(90-angles[j],angles[j]-90);
			if(di<dj)
			A[j]=0;
			else if(dj<di)
			A[i]=0;
			else
			A[max(i,j)]=0;
		}
	}
	vector <int> ans;
	for(int i=0;i<A.size();i++)
	{
		if(A[i]==1)
		ans.push_back(i);
	}
	return ans;
}


double test0() {
	int t0[] = {0, 40, 20, 10, 30, 50};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {105, 40, 30, 75, 135, 75};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Crossings * obj = new Crossings();
	clock_t start = clock();
	vector <int> my_answer = obj->getOut(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = { 0,  3,  5 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {0, 40, 20};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {40, 40, 140};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Crossings * obj = new Crossings();
	clock_t start = clock();
	vector <int> my_answer = obj->getOut(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = { 0,  1 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {10, 20};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {89, 91};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Crossings * obj = new Crossings();
	clock_t start = clock();
	vector <int> my_answer = obj->getOut(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = { 0 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
