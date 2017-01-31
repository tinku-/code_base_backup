#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	long long int a=0,b=0,c=0,p=0,ans=0;
	cin>>p;
	for(int i=1;i<=p;i++)
		{for(int j=1;j<=p;j++)
					{for(int k=1;k<=p;k++)
								{
									if(((i*i)+(j*j))==(k*k))
					                    {cout<<i<<" "<<j<<" "<<k<<"\n";
					                        if((i+j+k)==p)
					                      	{cout<<i*j*k;return 0;}}
								}
					}}
    return 0;
}