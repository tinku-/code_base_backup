#include <iostream>
using namespace std;
int main()
{
	long long int n,sum=0,k,ans=10000000,ANS;
	cin>>n>>k;
	long long int arr[1000000];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	for(int i=1;i<=k;i++)
	{
		sum = sum + arr[i];
	}
	ans = sum;
	// 	cout<<ans<<endl;
	for(int i=2;i<=(n-k+1);i++)
	{
		sum = sum - arr[i-1] + arr[k+i-1];
		//cout<<ans<<endl<<endl;
		if(ans > sum)
		{
			ans = sum;
			ANS = i;
		}
	}
	if(ANS>=2)
		cout<<ANS;
	else
		cout<<1;
	return 0;
}