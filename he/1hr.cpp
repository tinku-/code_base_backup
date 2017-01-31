#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int angry()
{
    long long int n,k,temp=0;cin>>n>>k;long long int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){if(a[i]<=0)temp++;}
    if(temp>=k)cout<<"NO"<<"\n";
    else cout<<"YES"<<"\n";
}
int main() {
    int t=0;cin>>t;for(int i=0;i<t;i++)angry();  
    return 0;
}
