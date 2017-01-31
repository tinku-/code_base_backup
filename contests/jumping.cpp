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
	long long int t=0;cin>>t;
	while(t--){
		long long int n,q,sum=0;
		cin>>n>>q;
		long long int h[n];
		for(int i=0;i<n;i++){
			cin>>h[i];
		}sort(h,h+n);
		for(int i=0;i<n-1;i++){
			sum=sum+(h[i+1]-h[i])*q;
		}cout<<sum<<endl;
	}
	return 0;
}