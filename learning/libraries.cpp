#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;
int main(){
	return 0;
}
#include <vector>
{
	int a,b;cin>>a>>b;
	vector<int> v;
	int size= v.size();            //size of vector ..............remember....(when using size of vector changes after pushabck or insert)
	v.push_back(a);                //pushes element from back 
	v.insert(v.begin(),b);	       //pushes element from front 

	for(int i=0;i<v.size();i++)cout<<v[i]; //prints the vector
}

#include <stack>
{
	stack<int> s;
	s.push(a);    //pushes element on top of stack
	s.top();      //returns top element of the stack
	s.pop();      //pop(remove) top element of stack 
	return 0;
}




