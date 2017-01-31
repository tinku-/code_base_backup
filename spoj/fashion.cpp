#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	long long int t;cin>>t;
	while(t--){
		long long int n;cin>>n;
		long long int m[n],w[n];
		for(int i=0;i<n;i++){
			cin>>m[i];
		}for(int i=0;i<n;i++){
			cin>>w[i];
		}sort(m,m+n);sort(w,w+n);
		long long int sum=0;
		for(int i=0;i<n;i++){
			sum=sum+m[i]*w[i];
		}cout<<sum<<endl;
	}return 0;
}