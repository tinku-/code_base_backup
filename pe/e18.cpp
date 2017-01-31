#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int n=0,m=0,sum=0,ans=0;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++){for(int j=0;j<n;j++){cin>>a[i][j];}}
	for(int k=0;k<n;k++)
	{
		int i=n-1;int j=n-1-k;sum=a[i][j];cout<<"\n"<<a[i][j]<<" - ";
		for(int l=0;l<n-1;l++)
	    {
	    	if(sum+a[i-1][j]>=sum+a[i-1][j-1]){sum=sum+a[i-1][j];i--;cout<<a[i][j]<<" - ";}
		    else if(sum+a[i-1][j-1]>=sum+a[i-1][j]){sum=sum+a[i-1][j-1];i--;j--;cout<<a[i][j]<<" - ";}
	    }
		if(sum>ans)ans=sum;
		sum=0;
	}
	cout<<"\n\n"<<ans<<"\n\n";
	return 0;
}
{
	a[i-1][j-1]=a[i-1][j-1]+max(a[i][j],a[i][j-1]);i--;j--;
}