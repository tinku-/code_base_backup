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
int canton(long long int n){
	long long int i=0,x=0;
	while(x<n){i++;x=i*(i+1)/2;}x=(i-1)*i/2;
	if(i%2==0){cout<<"TERM "<<n<<" IS "<<n-x<<"/"<<i+1-n+x<<endl;}
	else {cout<<"TERM "<<n<<" IS "<<i+1-n+x<<"/"<<n-x<<endl;}
	return 0;
}
int main(){
	int t=0;cin>>t;
	while(t--){
		long long int n;cin>>n;
		canton(n);
	}
	return 0;
}


//complete
