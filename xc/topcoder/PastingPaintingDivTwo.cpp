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
class PastingPaintingDivTwo {
public:
	long long countColors(vector <string>, int);
};

long long PastingPaintingDivTwo::countColors(vector <string> clip, int T)
{
	long long curr=0,coun=0,prev1=0;
	int l=clip.size(),b=clip[0].size();
	vector <string> A=clip;
	for(int i=0;i<clip.size();i++)
	{
		for(int j=0;j<clip[i].size();j++)
		{
			A[i][j]='.';
		}
	}
	while(coun<min(T,min(l,b)))
	{
		//prev2=prev1;
		prev1=curr;
		for(int i=0;i<clip.size()-1;i++)
		{
			for(int j=0;j<clip[0].size()-1;j++)
			{
				if(clip[i][j]=='B')
				{
					if(A[i+1][j+1]!='B')
					curr++;
					A[i+1][j+1]='B';
				}
			}
			if(clip[i][clip[i].size()-1]=='B')
			curr++;
			A[i+1].push_back(clip[i][clip[i].size()-1]);
		}
		A.push_back(clip[clip.size()-1]);
		for(int i=0;i<clip[0].size();i++)
		if(clip[clip.size()-1][i]=='B')
		curr++;
		A.erase(A.begin());
		for(int i=0;i<A.size()-1;i++)
		A[i].erase(A[i].begin());
		coun++;
		//cout<<coun<<" "<<curr<<" "<<prev1<<" "<<prev2<<"\n";
	}
	curr+=((T-coun)*(curr-prev1));
	return curr;	
}

double test0() {
	string t0[] = {
"..B",
"B..",
"BB."
};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 3;
	PastingPaintingDivTwo * obj = new PastingPaintingDivTwo();
	clock_t start = clock();
	long long my_answer = obj->countColors(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 10LL;
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
	string t0[] = {
"B...",
"....",
"....",
"...B"
};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	PastingPaintingDivTwo * obj = new PastingPaintingDivTwo();
	clock_t start = clock();
	long long my_answer = obj->countColors(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 4LL;
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
	string t0[] = {"BBB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 10000;
	PastingPaintingDivTwo * obj = new PastingPaintingDivTwo();
	clock_t start = clock();
	long long my_answer = obj->countColors(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 30000LL;
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
	string t0[] = {"."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1000000000;
	PastingPaintingDivTwo * obj = new PastingPaintingDivTwo();
	clock_t start = clock();
	long long my_answer = obj->countColors(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 0LL;
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
	string t0[] = {
"BB.",
".B."
};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 100;
	PastingPaintingDivTwo * obj = new PastingPaintingDivTwo();
	clock_t start = clock();
	long long my_answer = obj->countColors(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 201LL;
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
double test5() {
	string t0[] = {
"..........B..........",
".........B.B.........",
"........B...B........",
".......B.....B.......",
"......B..B.B..B......",
".....B...B.B...B.....",
"....B...........B....",
"...B...B.....B...B...",
"..B.....BBBBBB....B..",
".B..........BB.....B.",
"BBBBBBBBBBBBBBBBBBBBB"
};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1000000000;
	PastingPaintingDivTwo * obj = new PastingPaintingDivTwo();
	clock_t start = clock();
	long long my_answer = obj->countColors(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 21000000071LL;
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
