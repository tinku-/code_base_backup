#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int ans,n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		for(int i=0;i<n/2;i++)
			arr[i] = arr[i] + arr[n-1-i];
		ans = max_element(arr,arr+n/2) - min_element(arr,arr+n/2);

		if(ans > k)
			cout<<ans<<endl<<"No more girlfriends!"<<endl;
		else if(ans == k)
			cout<<ans<<endl<<"Lucky chap!"<<endl;
		else
			cout<<ans<<endl<<"Chick magnet Jhool!"<<endl;
	}
}