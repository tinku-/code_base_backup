#include <iostream>
using namespace std;
int main(){
	long long int a,b,c;cin>>a>>b>>c;
	while(a||b||c)	
    {
		if((b-a)==(c-b)){cout<<"AP "<<c+c-b<<"\n";}
			else {cout<<"GP "<<c*(c/b)<<"\n";}
		cin>>a>>b>>c;
	}
	return 0;
}	

