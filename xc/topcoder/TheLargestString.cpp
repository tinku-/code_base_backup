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

class TheLargestString
{
public:
void lpos(string,string,int &,char &);
string find(string,string);
};

double test0() {
	string p0 = "ab";
	string p1 = "zy";
	TheLargestString * obj = new TheLargestString();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "by";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "abacaba";
	string p1 = "zzzaaaa";
	TheLargestString * obj = new TheLargestString();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "cbaaaa";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "x";
	string p1 = "x";
	TheLargestString * obj = new TheLargestString();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "xx";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "abbabbabbababaaaabbababab";
	string p1 = "bababbaabbbababbbbababaab";
	TheLargestString * obj = new TheLargestString();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "bbbbbbbbbbbbbbbbbbaaab";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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

void TheLargestString::lpos(string s,string t,int &x,char &ch)
{
	char la=x;
	int i;
	if(x>=s.size())
	return;
	for(i=x;i<s.size();i++)
	{
		if(s[i]>s[la])
		{
			if(ch!=',')
			{
				if(s[i]>=ch)
					la=i;
			}
			else
			{
				la=i;
			}
		}
	}
	if(ch==',')
	{
		x=la;
		ch=t[x];
	}
	else
	{
		if(s[la]>=ch)
		{
			x=la;
			ch=t[x];
		}
	}
}	
string TheLargestString::find(string s, string t)
{
	vector <int> ans;
	string fans="";
	int x=-1;
	char ch=',';
	cout<<"jcb";
	while(x<s.size())
	{
		x++;
		lpos(s,t,x,ch);
		cout<<x;
		if(x<s.size())
		ans.push_back(x);
	}
	for(int i=0;i<ans.size();i++)
	fans+=s[ans[i]];
	for(int i=0;i<ans.size();i++)
	fans+=t[ans[i]];
	return fans;
}



//Powered by [KawigiEdit] 2.0!
