#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	long long int t;cin>>t;bool flag=false;
	for(int q=0;q<t;q++){
		long long int n;cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}sort(a,a+n);
		for(int i=0;i<n;i++){
			if(a[i]<=0)a[i]=0;
		}
		for( int i=0;i<n;i++){
			if(a[i]-temp && flag==false){
				cout<<i+1<<" ";flag=true;break;
			}
 	}if(flag==false){cout<<a[n-1]+1<<" ";}
	}return 0;
}