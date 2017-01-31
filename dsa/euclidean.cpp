#include <iostream>
#include <algorithm>
using namespace std;
int gcd1(long long int a,long long int b){   //recursive algorithm
	if(b==0)
		return a;
	else
		return gcd1(b,a%b);
}
int gcd2(long long int a,long long int b){   //while loop algorithm
	while(b){
		long long int temp=b;
		b=a%b;
		a=temp;
	}return a;
}
int main(){
	long long int t;cin>>t;
	while(t--){
	long long int a,b;
	cin>>a>>b;
	cout<<endl<<gcd2(a,b)<<endl;
	cout<<endl<<gcd1(a,b)<<endl;
	cout<<endl<<__gcd(a,b)<<endl;
	}return 0;
}


//euclidean algorithm ...........................................
