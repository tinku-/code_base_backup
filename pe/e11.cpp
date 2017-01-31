#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	long long int x=0,y=0,z=0;
	long long int a[20][20];
	for(int i=0;i<20;i++)for(int j=0;j<20;j++)cin>>a[i][j];
	for(int i=0;i<20;i++){cout<<"\n";for(int j=0;j<16;j++)
			{
				y=a[i][j]*a[i][1+j]*a[i][2+j]*a[i][3+j];
				x=max(x,y);y=1;cout<<" "<<x;
			}}
	for(int i=0;i<16;i++){cout<<"\n";for(int j=0;j<20;j++)
			{
				y=a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j];
				x=max(x,y);y=1;cout<<" "<<x;
			}}
	for(int i=0;i<16;i++){cout<<"\n";for(int j=0;j<16;j++)
			{
				y=a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3];
				x=max(x,y);y=1;cout<<" "<<x;}}
	for(int i=0;i<16;i++){cout<<"\n";for(int j=3;j<20;j++)
			{
				y=a[i][j]*a[i+1][j-1]*a[i+2][j-2]*a[i+3][j-3];
				x=max(x,y);y=1;cout<<" "<<x;
			}}
	cout<<"\n\n"<<x<<"\n\n";
	return 0;
}

