#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
	double ans=0;
	long long int a[50];
	for(int i=0;i<50;i++)a[i]=0;
	char c[100][50];
	for(int i=0;i<100;i++)for(int j=0;j<50;j++)cin>>c[i][j];
	for(int i=0;i<100;i++){cout<<"\n";for(int j=0;j<50;j++)cout<<c[i][j]<<" ";}
    for(int j=0;j<100;j++)for(int i=0;i<100;i++){a[j]=a[j]+(c[i][j]-'0');}
    for(int i=0;i<50;i++)ans=ans*10+a[i];
    for(int i=0;i<50;i++)cout<<" "<<i+1<<"  "<<a[i];
    cout<<"\n\n"<<fixed<<ans<<"\n\n";
	return 0;
}	
