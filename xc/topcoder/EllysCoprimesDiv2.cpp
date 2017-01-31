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
int prime[100001]={0,0};
vector <int> primes;
void process()
{
	for(int i=2;i<=100000;i++)
	{
		if(prime[i]==0)
		{
			primes.push_back(i);
			for(int j=2*i;j<=100000;j+=i)
			prime[j]=-1;
		}
	}
}
int process(int x,int y)
{
	int i,j;
	for(i=x+1;i<y;i++)
	{
		for(j=0;primes[j]<=i;j++)
		{
			if(i%primes[j]==0)
			{
				if((x%primes[j]==0)||(y%primes[j]==0))
				break;
			}
		}
		if(primes[j]<=i)
		continue;
		else
		return 1;
	}
	return 2;
}
class EllysCoprimesDiv2 {
public:
	int getCount(vector <int>);
};

int EllysCoprimesDiv2::getCount(vector <int> numbers)
{
	sort(numbers.begin(),numbers.end());
	process();
	int ans=0;
	for(int i=0;i<numbers.size()-1;i++)
	{
		int j;
		for(j=0;primes[j]<=min(numbers[i],numbers[i+1]);j++)
		{
			if((numbers[i]%primes[j]==0)&&(numbers[i+1]%primes[j]==0))
			break;
		}
		if((numbers[i]%primes[j]==0)&&(numbers[i+1]%primes[j]==0))
		{
			ans+=process(numbers[i],numbers[i+1]);
		}
	}
	return ans;	
}


double test0() {
	int t0[] = {2200, 42, 2184, 17};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysCoprimesDiv2 * obj = new EllysCoprimesDiv2();
	clock_t start = clock();
	int my_answer = obj->getCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
	int t0[] = {13, 1, 6, 20, 33};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysCoprimesDiv2 * obj = new EllysCoprimesDiv2();
	clock_t start = clock();
	int my_answer = obj->getCount(p0);
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
double test2() {
	int t0[] = {7, 42};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysCoprimesDiv2 * obj = new EllysCoprimesDiv2();
	clock_t start = clock();
	int my_answer = obj->getCount(p0);
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
double test3() {
	int t0[] = {55780, 44918, 55653, 4762, 41536, 40083, 79260, 7374, 24124, 91858, 7856,
 12999, 64025, 12706, 19770, 71495, 32817, 79309, 53779, 8421, 97984, 34586,
 893, 64549, 77792, 12143, 52732, 94416, 54207, 51811, 80845, 67079, 14829,
 25350, 22976, 23932, 62273, 58871, 82358, 13283, 33667, 64263, 1337, 42666};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	EllysCoprimesDiv2 * obj = new EllysCoprimesDiv2();
	clock_t start = clock();
	int my_answer = obj->getCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 15;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
