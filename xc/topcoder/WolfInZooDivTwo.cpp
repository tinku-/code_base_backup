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

class WolfInZooDivTwo {
public:
	int count(int, vector <string>, vector <string>);
};

int WolfInZooDivTwo::count(int N, vector <string> L, vector <string> R)
{
	vector <int> l,r;
	string left,right;
	for(int i=0;i<L.size();i++)
	left+=L[i];
	for(int i=0;i<R.size();i++)
	right+=R[i];
	for(int i=0;i<left.size();i++)
	{
		int x=0;
		if(left[i]==' ')
		continue;
		while(left[i]!=' ')
		{
			x=(x*10)+(left[i]-'0');
			i++;
			if(i>=left.size())
			break;
		}
		l.push_back(x);
	}
	for(int i=0;i<right.size();i++)
	{
		int x=0;
		if(right[i]==' ')
		continue;
		while(right[i]!=' ')
		{
			x=(x*10)+(right[i]-'0');
			i++;
			if(i>=right.size())
			break;
		}
		r.push_back(x);
	}
	for(int i=0;i<l.size();i++)
	cout<<l[i]<<" "<<r[i]<<"\n";
	vector <int> ad,su,grid(N,0);
	for(int i=0;i<l.size();i++)
	{
		ad.push_back(r[i]+1-l[i]);
		for(int j=l[i];j<=r[i];j++)
		grid[j]++;
	}
	while(grid.size()!=0)
	{
		int i,x=grid[0];
		for(i=1;i<grid.size();i++)
		{
			if(grid[i]!=x)
			break;
		}
		for(int j=1;j<x;j++)
		su.push_back(i);
		grid.erase(grid.begin(),grid.begin()+i);
	}
	int ans=0,ansa=0,anss=0;
	for(int i=0;i<ad.size();i++)
	{
		int x=1;
		for(int j=0;j<ad[i];j++)
		{
			x*=2;
			x%=1000000007;
		}
		x--;
		ansa+=x;
		ansa%=1000000007;
	}
	for(int i=0;i<su.size();i++)
	{
		int x=1;
		for(int j=0;j<su[i];j++)
		{
			x*=2;
			x%=1000000007;
		}
		x--;
		anss+=x;
		anss%=1000000007;
	}	
	ans=ansa-anss;
	if(ans<0)
	ans+=1000000007;
	return ans;
}


double test0() {
	int p0 = 5;
	string t1[] = {"0 1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"2 4"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	WolfInZooDivTwo * obj = new WolfInZooDivTwo();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 27;
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
	int p0 = 10;
	string t1[] = {"0 4 2 7"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"3 9 5 9"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	WolfInZooDivTwo * obj = new WolfInZooDivTwo();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 798;
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
	int p0 = 100;
	string t1[] = {"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	WolfInZooDivTwo * obj = new WolfInZooDivTwo();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 250671525;
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
	int p0 = 3;
	string t1[] = {"1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"2"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	WolfInZooDivTwo * obj = new WolfInZooDivTwo();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 6;
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
