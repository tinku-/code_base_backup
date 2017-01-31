#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;
int divisors(long long int a) 
{
	int i=1,ans=0,temp=1;
	while(i<=a){if(a%i==0){ans++;if(temp*i==a){ans=(ans-1)*2;break;}temp=i;}i++;}
    return ans;
}
int main()
{
	clock_t t1,t2;
    t1=clock();
	long long int n=0,t=0,ans=1,i=0,k;cin>>k;
	while(divisors(n)<=k)
	{
		i++;n=i*(i+1)/2;
	}
	cout<<"\n"<<i<<" "<<n<<"\n";
	t2=clock();
    float diff ((float)t2-(float)t1);
    cout<<fixed<<diff<<endl;
    //system ("pause");
    return 0;
}
