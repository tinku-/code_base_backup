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

class CharacterBoard2 {
public:
	int countGenerators(vector <string>, int, int, int);
};

int CharacterBoard2::countGenerators(vector <string> fragment, int W, int i0, int j0)
{
	int fans=0,hei=fragment.size(),bre=fragment[0].size();
	cout<<hei<<" "<<bre<<"\n";
	long long ans=0;
	for(int i=1;i<=W;i++)
	{
		vector <char> A;
		for(int j=0;j<i;j++)
		A.push_back('_');
		int f=0;
		for(int r=i0;r<i0+hei;r++)
		{
			for(int c=j0;c<j0+bre;c++)
			{
				if(A[((r*W)+c)%i]=='_')
				A[((r*W)+c)%i]=fragment[r-i0][c-j0];
				else
				{
					if(A[((r*W)+c)%i]!=fragment[r-i0][c-j0])
					{
						f=1;
						break;
					}
				}
			}
			if(f==1)
			break;
		}
		if(f==0)
		{
			long long count=1;
			for(int j=0;j<i;j++)
			if(A[j]=='_')
			{
				count*=26;
				count%=1000000009;
			}
			ans+=count;
			ans%=1000000009;
		}
	}
	ans%=1000000009;
	fans+=ans;
	return fans;
}

double test0() {
	string t0[] = {"dea",
 "abc"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 7;
	int p2 = 1;
	int p3 = 1;
	CharacterBoard2 * obj = new CharacterBoard2();
	clock_t start = clock();
	int my_answer = obj->countGenerators(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"xyxxy"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 6;
	int p2 = 1;
	int p3 = 0;
	CharacterBoard2 * obj = new CharacterBoard2();
	clock_t start = clock();
	int my_answer = obj->countGenerators(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 28;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"gogogo",
 "jijiji",
 "rarara"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 6;
	int p2 = 0;
	int p3 = 0;
	CharacterBoard2 * obj = new CharacterBoard2();
	clock_t start = clock();
	int my_answer = obj->countGenerators(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"abababacac",
 "aaacacacbb",
 "ccabababab"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 882;
	int p2 = 10;
	int p3 = 62;
	CharacterBoard2 * obj = new CharacterBoard2();
	clock_t start = clock();
	int my_answer = obj->countGenerators(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 361706985;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"asjkffqw",
 "basjkffq",
 "qbasjkff",
 "qqbasjkf"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 9031;
	int p2 = 9024;
	int p3 = 1959;
	CharacterBoard2 * obj = new CharacterBoard2();
	clock_t start = clock();
	int my_answer = obj->countGenerators(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 173947456;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
