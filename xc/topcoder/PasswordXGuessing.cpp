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

class PasswordXGuessing {
public:
	long long howMany(vector <string>);
	int func(string,string);
};
int PasswordXGuessing::func(string x,string y)
{
	int ans=0;
	for(int i=0;i<x.size();i++)
	{
		if(x[i]!=y[i])
		ans++;
	}
	return ans;
}
long long PasswordXGuessing::howMany(vector <string> guesses)
{
	long long ans=0;
	for(int i=0;i<guesses[0].size();i++)
	{
		string x;
		//cout<<"i:"<<i<<"\n";
		for(int j=0;j<10;j++)
		{
			//cout<<"j:"<<j<<"\n";
			x=guesses[0];
			if(char(j+'0')==x[i])
			continue;
			x[i]=char(j+'0');
			int k;
			for(k=0;k<guesses.size();k++)
			{
				if(func(x,guesses[k])!=1)
				break;
			}
			if(k==guesses.size())
			ans++;
		}
	}
	return ans;
}

double test0() {
	string t0[] = {"58", "47"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PasswordXGuessing * obj = new PasswordXGuessing();
	clock_t start = clock();
	long long my_answer = obj->howMany(p0);
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
double test1() {
	string t0[] = {"539", "540", "541"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PasswordXGuessing * obj = new PasswordXGuessing();
	clock_t start = clock();
	long long my_answer = obj->howMany(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 1LL;
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
	string t0[] = {"12", "34", "56", "78"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PasswordXGuessing * obj = new PasswordXGuessing();
	clock_t start = clock();
	long long my_answer = obj->howMany(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 0LL;
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
	string t0[] = {"2", "3", "5"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PasswordXGuessing * obj = new PasswordXGuessing();
	clock_t start = clock();
	long long my_answer = obj->howMany(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 7LL;
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
	string t0[] = {"4747", "4747", "4747", "4747"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PasswordXGuessing * obj = new PasswordXGuessing();
	clock_t start = clock();
	long long my_answer = obj->howMany(p0);
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
