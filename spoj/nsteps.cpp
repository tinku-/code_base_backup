#include <iostream>
using namespace std;
int main(){
long long int t;cin>>t;
while(t--)
	{ 
		long long int a=0,b=0;cin>>a>>b;
		if(a==b)cout<<(a/2)*2+a<<"\n";
		else if(a==(b+2))cout<<2+(b/2)*2+b<<"\n";
		    else cout<<"No Number"<<"\n";
	}
}