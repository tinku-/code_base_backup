//recursive fibonacci sunction
#include <iostream>
using namespace std;
int fib(long long int n){
	if(n==0 || n==1)
		return n;
	else
		return (fib(n-1)+fib(n-2));
}
//driver function
int main(){
	long long int a;
	cin>>a;
	cout<<fib(a);
	return 0;
}