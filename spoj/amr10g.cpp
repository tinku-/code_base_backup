#include <bits/stdc++.h>
using namespace std;
int arr[20004] = {0};
int main()
{
	int n,k,ans;
	int t;cin>>t;while(t--){
		ans = 1000000000;
		cin>>n>>k;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		for(int i=0;i<n-k+1;i++)
		{
			if((arr[i+k-1] - arr[i]) < ans)
				ans = arr[i+k-1] - arr[i];
		}
		cout<<ans<<endl;
	}
}