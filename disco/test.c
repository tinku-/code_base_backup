#include <stdio.h>
#include <iostream>
int binarytoint(long long int arr[32]){
	unsigned long long int z=1;
	unsigned long long int sum=0;
	for(int i=0;i<32;i++){
		if(arr[31-i]==1){
			sum=sum+z;
		}z=z*2;
	}return sum;
}
int intobinary(long long int arr[32],long long int a){
	long long int i=0;
	while(a){
		arr[31-i]=a%2;
		a=a/2;i++;
	}return 0;
}
int main(){
	unsigned long long int t,a,j;
	scanf("%lld",&t);
	while(t--){
		unsigned long long int x=0;
		scanf("%lld %lld",&a,&j);
	    long long int arr1[32]={0},arr2[32]={0},ans[32]={0};
		intobinary(arr1,a);intobinary(arr2,j);
		for(int i=0;i<32;i++){
			if(arr1[i]==1 || arr2[i]==1){
				ans[i]=1;
			} 
		}x=binarytoint(ans);for(int i=0;i<32;i++){ans[i]=0;}
		printf("%lld\n",x);x=0;
		for(int i=0;i<32;i++){
			if(arr1[i]==1 && arr2[i]==1){
				ans[i]=1;
			}
		}x=binarytoint(ans);for(int i=0;i<32;i++){ans[i]=0;}
		printf("%lld\n",x);x=0;
		for(int i=0;i<32;i++){
			if(arr2[i]==0){
				ans[i]=1;
			}
		}x=binarytoint(ans);
		for(int i=0;i<32;i++){printf("%lld",ans[i]);}printf("\n");
		for(int i=0;i<32;i++){ans[i]=0;}
		printf("%lld\n",x);x=0;
		for(int i=0;i<32;i++){
			if(arr1[i]==1 && arr2[i]==0){
				ans[i]=1;
			}
		}x=binarytoint(ans);
		printf("%lld\n",x);x=0;
		for(int i=0;i<32;i++){
			if(arr1[i]==1)
				x++;
		}printf("%lld",x);x=0;
	}
}