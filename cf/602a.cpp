#include <iostream>
using namespace std;
int main(){
	long long int x=0,y=0,b,n,t=0;
	cin>>n>>b;
	while(n--){
		cin>>t;
		x = x*b + t;
	}cin>>n>>b;
	while(n--){
		cin>>t;
		y = y*b + t;
	}//cout<<endl<<x<<endl<<y<<endl;
	if(x > y){cout<<">";}
	if(x < y){cout<<"<";}
	if(x == y){cout<<"=";}
	return 0;
}
//begnning of new era ...........................