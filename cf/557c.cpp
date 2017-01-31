#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main() 
{
	int n;cin>>n;
	pair<int,int> a[n];
	for(int i=0;i<n;i++)cin>>a[i].first;
	for(int i=0;i<n;i++)cin>>a[i].second;
	sort(a,a+n);
    
    for(int i=0;i<n;i++)cout<<a[i].first<<" ";cout<<"\n";
	for(int i=0;i<n;i++)cout<<a[i].second<<" ";
	return 0;
}
