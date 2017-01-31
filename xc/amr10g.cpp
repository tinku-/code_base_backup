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
		for(int i=0;i<n-k;i++)
		{
			if(arr[i+k] - arr[k] < ans)
				ans = arr[i+k] - arr[k];
		}
		cout<<ans<<endl;
	}
}