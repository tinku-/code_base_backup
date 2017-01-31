#include <iostream>
#include <cmath>
using namespace std;
int prime(long long int a)
{
	bool flag=true;
	long long int b=pow(a,0.5);
	for(int i=2;i<=b;i++)
		{if(a%i==0){flag=false;return flag;}}
	return flag;
}
int main()
{
	int n;cin>>n;
	long long int temp=0,ans=0,ans1=0,ans2=0;
	for(int i=-1*n;i<=n;i++)
		{   
			for(int j=-1*n;j<=n;j++)
			{
				int k=0;int t=j;
				while(t>0 && prime(t)==true){t=((k*k)+(i*k)+j);k++;}
			    if(k>temp){temp=k;ans=i*j;ans1=i;ans2=j;}
			}
		}
	for(int i=0;i<-1*ans;i++)
		cout<<(i*i+ans1*i+ans2)<<"\n\n";
    cout<<"\n\n"<<ans1<<"*"<<ans2<<"="<<ans<<"\n\n"<<temp;return 0;	
}