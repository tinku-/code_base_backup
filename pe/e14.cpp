#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	long long int n,t=0,t1=0,t2=0,ans=0;
	cin>>n;
	for(int i=0;i<=n;i++)
		{
			t1=i;
			while(t1>1)
			{
			    if(t1%2==0){t1=t1/2;t2++;}
			    else{t1=3*t1+1;t2++;}	
			}
			if(t2>t){t=t2;ans=i;cout<<" "<<ans<<" ";}t2=0;
		}
	cout<<"\n\n"<<ans<<"\n\n";
	return 0;
}