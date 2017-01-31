#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	multiset < int > s;
	multiset < int > :: iterator it;
	for(int i=0;i<n;i++)
	{
	    s.insert(arr[i]);  
    	it = s.lower_bound(arr[i]);
    	it++;
    	if(it != s.end())
    	    s.erase(it);
	}
	cout << s.size();
	return 0;
}