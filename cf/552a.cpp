#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	long long int n,x1,y1,x2,y2,sum=0;
	int a[100][100];
	for(int i=0;i<100;i++)for(int j=0;j<100;j++)a[i][j]=0;
	cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>x1>>y1>>x2>>y2;
        for(int i=x1-1;i<=x2-1;i++)for(int j=y1-1;j<=y2-1;j++)a[i][j]++;}
    for(int i=0;i<100;i++)for(int j=0;j<100;j++)sum=sum+a[i][j];
    cout<<sum;
	return 0;
}

/*far better solution 
#include <iostream>
using namespace std;
int main(){
	int n,x,y,z,w,ans=0;
	cin>>n;
	while(n--){
		cin>>x>>y>>z>>w;
		ans+=(z-x+1)*(w-y+1);
	}
	cout<<ans;
}