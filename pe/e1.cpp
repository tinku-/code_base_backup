#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	int n,sum=0;
	cin>>n;
	for(int i=1;i<n;i++){
	if(i%3==0)sum=sum+i;
	else if(i%5==0)sum=sum+i;
	}
	cout<<sum;
	return 0;
}
