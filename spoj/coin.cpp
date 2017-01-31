#include <iostream>
#include <map>
using namespace std;
map<long long,long long> m;
long long coin(long long k)
{
	if(k<12)
		{if(!m[k]){m[k]=k;return m[k];}}
	else
	{
		if(!m[k])
			m[k]=coin(k/2)+coin(k/3)+coin(k/4);
	}
	return m[k];
}
int main(){
	long long int n=0;
	while(cin>>n){
		cout<<coin(n)<<endl;
	}
	return 0;
}



//THIS is an example of memoization DP.............
