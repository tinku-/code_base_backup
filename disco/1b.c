#include <stdio.h>
#include <math.h>
long long int function1(long long int arr[32]){
	unsigned long long int z=1,i=0;
	unsigned long long int sum=0;
	for(i=0;i<32;i++){
		sum=sum+arr[31-i]*z;
		z=z*2;
	}return sum;
}
long long int function2(long long int arr[32],long long int a){
	long long int i=0;
	while(a){
		arr[31-i]=a%2;
		a=a/2;i++;
	}return 0;
}
int main(){
	unsigned long long int t,a,j,i=0;
	scanf("%lld",&t);
	while(t--){
		unsigned long long int x=0;
		scanf("%lld %lld",&a,&j);
	    long long int arr1[32],arr2[32],ans[32];
	    for(i=0;i<32;i++){ans[i]=0;arr1[i]=0;arr2[i]=0;}
		function2(arr1,a);function2(arr2,j);
		for(i=0;i<32;i++){
			if(arr1[i]==1 || arr2[i]==1){
				ans[i]=1;
			} 
		}x=function1(ans);for(i=0;i<32;i++){ans[i]=0;}
		printf("%llu\n",x);x=0;
		for(i=0;i<32;i++){
			if(arr1[i]==1 && arr2[i]==1){
				ans[i]=1;
			}
		}x=function1(ans);for(i=0;i<32;i++){ans[i]=0;}
		printf("%llu\n",x);x=0;
		for(i=0;i<32;i++){
			if(arr2[i]==0){
				ans[i]=1;
			}
		}x=function1(ans);
		for(i=0;i<32;i++){ans[i]=0;}
		printf("%llu\n",x);x=0;
		for(i=0;i<32;i++){
			if(arr1[i]==1 && arr2[i]==0){
				ans[i]=1;
			}
		}x=function1(ans);
		printf("%llu\n",x);x=0;
		for(i=0;i<32;i++){
			if(arr1[i]==1)
				x++;
		}printf("%llu",x);x=0;
		printf("\n");
	}return 0;
}