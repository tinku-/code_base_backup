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

class SurveillanceSystem {
public:
	string getContainerInfo(string, vector <int>, int);
};

string SurveillanceSystem::getContainerInfo(string containers, vector <int> reports, int L)
{
	int N=containers.size();
	vector <int> totalrep;
	for(int i=0;i<=N-L;i++)
	{
		int counter=0;
		for(int j=0;j<L;j++)
		{
			if(containers[i+j]=='X')
			counter++;
		}
		totalrep.push_back(counter);
	}
	string ans;
	vector <int> trc(N+1,0),rc(N+1,0),irc(N+1,0);
	for(int i=0;i<=N;i++)
	{
		int counter=0;
		for(int j=0;j<totalrep.size();j++)
		if(totalrep[j]==i)
		counter++;
		trc[i]=counter;
	}
	for(int i=0;i<=N;i++)
	{
		int counter=0;
		for(int j=0;j<reports.size();j++)
		if(reports[j]==i)
		counter++;
		rc[i]=counter;
	}
	for(int i=0;i<N;i++)
	{
		vector <int> irep;
		for(int j=max(0,i+1-L);j<=min(i,N-L);j++)
		{
			int counter=0;
			for(int k=0;k<L;k++)
			{
				if(containers[j+k]=='X')
				counter++;
			}
			irep.push_back(counter);
		}
		for(int j=0;j<=N;j++)
		{
			int counter=0;
			for(int k=0;k<irep.size();k++)
			if(irep[k]==j)
			counter++;
			irc[j]=counter;
		}
		bool candowithout=true,candowith=false;
		for(int j=0;j<=N;j++)
		{
			if((trc[j]-irc[j])<rc[j])
			candowithout=false;
			if((rc[j]>0)&&(irc[j]>0))
			candowith=true;
		}
		if(candowithout&&candowith)
		ans+='?';
		else if(candowithout&&!candowith)
		ans+='-';
		else
		ans+='+';
	}
	return ans;
}

double test0() {
	string p0 = "-X--XX";
	int t1[] = {1, 2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	SurveillanceSystem * obj = new SurveillanceSystem();
	clock_t start = clock();
	string my_answer = obj->getContainerInfo(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "??++++";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "-XXXXX-";
	int t1[] = {2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	SurveillanceSystem * obj = new SurveillanceSystem();
	clock_t start = clock();
	string my_answer = obj->getContainerInfo(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "???-???";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "------X-XX-";
	int t1[] = {3, 0, 2, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 5;
	SurveillanceSystem * obj = new SurveillanceSystem();
	clock_t start = clock();
	string my_answer = obj->getContainerInfo(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "++++++++++?";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "-XXXXX---X--";
	int t1[] = {2, 1, 0, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	SurveillanceSystem * obj = new SurveillanceSystem();
	clock_t start = clock();
	string my_answer = obj->getContainerInfo(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "???-??++++??";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = "-XX--X-XX-X-X--X---XX-X---XXXX-----X";
	int t1[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 7;
	SurveillanceSystem * obj = new SurveillanceSystem();
	clock_t start = clock();
	string my_answer = obj->getContainerInfo(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "???++++?++++++++++++++++++++??????--";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}


//Powered by [KawigiEdit] 2.0!
