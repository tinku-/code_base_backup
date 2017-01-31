#include <iostream>
#include <algorithm>
using namespace std;
double arr[12][12] = {0};
int main()
{
	int n,t,ans = 0;
	cin>>n>>t;
	arr[1][1] = t;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
		{
			if(arr[i][j] >= 1)
			{
				arr[i+1][j] += (arr[i][j]-1.0)/2.0;
				arr[i+1][j+1] += (arr[i][j]-1.0)/2.0;
				ans++;
			}

		}
	cout<<ans;
}