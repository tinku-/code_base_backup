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
#include <string>

using namespace std;
bool isvalidbc(string A)
{
	int year=0,month=0,day=0;
	year=((A[0]-'0')*1000)+((A[1]-'0')*100)+((A[2]-'0')*10)+(A[3]-'0');
	month=((A[4]-'0')*10)+(A[5]-'0');
	day=((A[6]-'0')*10)+(A[7]-'0');
	if(year<1900)
	return false;
	if(year>2011)
	return false;
	switch(month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:if(day>31)
			return false;
			break;
		case 4:
		case 6:
		case 9:
		case 11:if(day>30)
			return false;
			break;
		case 2:if(year%4==0)
			{
				if(year%100==0)
				{
					if(year%400==0)
					{
						if(day>29)
						return false;
					}
					else
					{
						if(day>28)
						return false;
					}
				}
				else
				{
					if(day>29)
					return false;
				}
			}
			else
			{
				if(day>28)
				return false;
			}
			break;
	}
	return true;
}
char calcchecksum(string A)
{
	long long int x=0,y;
	double xy;
	for(int i=0;i<17;i++)
	{
		xy=pow(2.0,17-i);
		y=(long long int)xy;
		x+=(A[i]-'0')*y;
	}
	x%=11;
	x=12-x;
	x%=11;
	if(x==10)
	return 'X';
	char ans;
	ans=x+'0';
	return ans;
}
string checkgender(string A)
{
	switch(A[2])
	{
		case '0':
		case '2':
		case '4':
		case '6':
		case '8':return "Female";
			break;
	}
	return "Male";
}
class IDNumberVerification {
public:
	string verify(string, vector <string>);
};

string IDNumberVerification::verify(string id, vector <string> regionCodes)
{
	string RC,BC,SC;
	char CS;
	RC=id.substr(0,6);
	BC=id.substr(6,8);
	SC=id.substr(14,3);
	CS=id[17];
	int i;
	for(i=0;i<regionCodes.size();i++)
	{
		if(regionCodes[i]==RC)
		break;
	}
	if(i>=regionCodes.size())
	return "Invalid";
	if(!isvalidbc(BC))
	return "Invalid";
	if(SC=="000")
	return "Invalid";
	if(CS!=calcchecksum(id))
	return "Invalid";
	return checkgender(SC);
}


double test0() {
	string p0 = "441323200312060636";
	string t1[] = {"441323"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	IDNumberVerification * obj = new IDNumberVerification();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Male";
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
	string p0 = "62012319240507058X";
	string t1[] = {"620123"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	IDNumberVerification * obj = new IDNumberVerification();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Female";
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
	string p0 = "321669197204300886";
	string t1[] = {"610111","659004"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	IDNumberVerification * obj = new IDNumberVerification();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Invalid";
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
	string p0 = "230231198306900162";
	string t1[] = {"230231"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	IDNumberVerification * obj = new IDNumberVerification();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Invalid";
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
double test4() {
	string p0 = "341400198407260005";
	string t1[] = {"341400"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	IDNumberVerification * obj = new IDNumberVerification();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Invalid";
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
double test5() {
	string p0 = "520381193206090891";
	string t1[] = {"532922","520381"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	IDNumberVerification * obj = new IDNumberVerification();
	clock_t start = clock();
	string my_answer = obj->verify(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Invalid";
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
