#include <iostream>
using namespace std;
int main(){
	long long int t;cin>>t;
	for(int T=0;T<t;T++){
		long long int n;cin>>n;
		cout<<(n*(n+2)*(2*n+1))/8<<endl;
	}
}