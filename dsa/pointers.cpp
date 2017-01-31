#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	int a;
	int *p;
	p=&a;
	a=5;
	cout<<"\n\n"<<p<<"\n"<<&a<<"\n"<<&p<<"\n"<<*p<<"\n\n";
}