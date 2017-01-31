#include <iostream>
#include <vector>
using namespace std;
int sumd(long long int a)
{
	long long int d=0;
	for(int i=1;i<a;i++)if(a%i==0)d=d+i;
	return d;
}
bool check(long long int a)
{bool f=false;if(sumd(sumd(a))==a && a!=sumd(a))f=true;}
int main()
{
	long long int x,ans=0;cin>>x;
	for(int i=1;i<=x;i++){if(check(i)==true)ans=ans+i;}
	cout<<"\n\n"<<ans<<"\n\n";
    return 0;
}