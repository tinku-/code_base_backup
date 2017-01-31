#include <iostream>
using namespace std;
int fun(long long int x,string s){
	char a[s.size()/x][x];long long int k=0;
	for(int i=0;i<s.size()/x;i++)for(int j=0;j<x;j++){if(i%2==0){a[i][j]=s[k];k++;}else{a[i][x-1-j]=s[k];k++;}}
	for(int i=0;i<x;i++)for(int j=0;j<s.size()/x;j++)cout<<a[j][i];
	cout<<"\n";return 0;
}
int main(){
	long long int x;string s;
	cin>>x>>s;
	for(;;)
	{
		if(x!=0){fun(x,s);cin>>x;if(x==0){return 0;}else{cin>>s;}}
	}
	return 0;
}