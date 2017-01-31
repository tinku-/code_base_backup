//first recursion.
#include <iostream>
using namespace std;
int factorial(long long int n){
	cout<<"i am calculating F("<<n<<")\n";
	if(n==0)
		return 1;
	long long int f = n*factorial(n-1);
	cout<<"Done ! f("<<n<<")="<<f<<"\n";
	return f;
}
int main(){
	long long int a;
	cin>>a;
	cout<<factorial(a);
	return 0;
}


//factorial recurssion....................................................