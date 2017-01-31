#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	long long  int t=0;cin>>t;
	for(int T=0;T<t;T++){
		long long int k;cin>>k;
		if(k%2==0){
			cout<<442+(k/2-1)*500<<endl;
		}
		else{
			cout<<192+(k/2)*500<<endl;
		}
	}
	return 0;
}