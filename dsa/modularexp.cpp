#include <iostream>
using namespace std;
int exp(long long int a,long long int n,long long int m){
	int power = a%m;
	int x=1;
	int temp=0;
	while(n != 0)
	{
		temp = n%2;
		n = n/2;
		if(temp == 1)
			x = (x*power)%m;
		power = (power*power)%m;
		//cout<<power<<endl;
	}return x;
}
int main(){
	long long int a,b,n,c,m;
	cin>>a>>n>>m;
	cout<<exp(a,n,m);
	return 0;
}


//modular exponentiation algorithm for finding remainders of huge powers 
