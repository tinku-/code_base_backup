#include <iostream>
using namespace std;
int main(){
	long long int t;cin>>t;
	for(int T=0;T<t;T++){
		long long int n;long long sum=0;cin>>n;

		for(int i=0;i<n;i++)
		{
			long long int a;cin>>a;
			sum=sum+a%n;
			if(sum%n==0)sum=0;
		}if(sum%n==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}