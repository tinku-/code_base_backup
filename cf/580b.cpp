#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <set>
using namespace std;
int main(){
	long long int n,d;cin>>n>>d;
	pair <long long int,long long int> a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
	}sort(a,a+n);cout<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i].first<<" "<<a[i].second<<endl;
	}
	long long int end=0,temp=0,ans=0,sum=0;
	for(int i=0;i<n;i++){
		if((a[i].first-a[end].first)<d){
			sum=sum+a[i].second;
		}while((a[i].second-a[end].second)>=d){
			sum=sum-a[end].second;
			end++;
		}//ans=max(ans,sum);
	}ans=max(ans,sum);
	cout<<ans;
	return 0;
}

		while(a){
			arr1[31-i]=a%2;
			a=a/2;i++;
		}i=0;
		while(j){
			arr2[31-i]=j%2;
			j=j/2;i++;
		}