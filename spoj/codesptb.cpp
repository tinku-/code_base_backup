#include <iostream>
using namespace std;
int insertionsort(long long int a[],long long int n){
	long long int ans=0;
	for(int i=1;i<n;i++){
		long long int key=a[i];
		long long int j=i-1;
		while(j>=0 && a[j]>key){
			(a[j+1]=a[j]);
			(a[j]=key);
			j--;
			ans++;
		}
	}return ans;
}
int main(){
	long long int t=0;cin>>t;
	while(t--){
		long long int n;cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}cout<<insertionsort(a,n)<<endl;
	}return 0;
}