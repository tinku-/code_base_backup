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
int dis(int x1,int y1,int x2,int y2){
	int distance = abs(x1-x2)+abs(y1-y2);
	return distance;
}
int main(){
	int n,sumx=0,sumy=0;cin>>n;
	int x[n],y[n],a[n-1];
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}sort(x,x+n);	
	sort(y,y+n);
	if((n-1)%2==0){
		int z=n-1;
		for(int i=0;i<n/2;i++){
			a[i]=z*(i+1)+(i+1)*i;
			a[n-2-i]=a[i];
			z=z-2;
		}
	}else {
		int z=n-1;
		for(int i=0;i<n/2+1;i++){
			a[i]=z*(i+1)+(i+1)*i;
			a[n-2-i]=a[i];
			z=z-2;
		}
	}
	/*for(int i=0;i<n-1;i++){
		cout<<a[i]<<" ";
	}cout<<endl;*/
	for(int i=0;i<n-1;i++){
		sumx=sumx+(a[i]*(x[i+1]-x[i]))%1000000007;
		sumy=sumy+(a[i]*(y[i+1]-y[i]))%1000000007;
		sumy=sumy%1000000007;
		sumx=sumx%1000000007;
	}sumx=sumx%1000000007+sumy%1000000007;
	cout<<sumx%1000000007;
	return 0;
}

//galat hai ye ????