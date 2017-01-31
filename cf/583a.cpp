#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;
int main(){
	long long int n,x,y,z;
	cin>>n;z=n*n;
	long long int a[z+1],b[z+1];
	for(int i=1;i<=z;i++){
		a[i]=0;
		b[i]=0;
	}for(int i=1;i<=z;i++){
		cin>>x>>y;
		if(a[x]==0 && b[y]==0){
			a[x]=1;b[y]=1;
			cout<<i<<" ";
		}
	}
	return 0;
}

