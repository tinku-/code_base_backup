#include <stdio.h>

int binarytoint(int arr[32]){
	long long int z=1;
	long long int sum=0;
	for(int i=0;i<32;i++){
		if(arr[31-i]==1){
			sum=sum+z;
		}z=z*2;
	}return sum;
}
int intobinary(int arr[32],long long int a){
	long long int i=0;
	while(a){
		arr[31-i]=a%2;
		a=a/2;i++;
	}return 0;
}
int main(){
	long long int t,a,j;
	scanf("%lld",&t);
	while(t--){
		long long int x=0;
		scanf("%lld %lld",&a,&j);
	    int arr1[32]={0},arr2[32]={0},ans[32]={0};
		intobinary(arr1,a);intobinary(arr2,j);
		for(int i=0;i<32;i++){
			if(arr1[i]==1 || arr2[i]==1){
				ans[i]=1;
			}
		}x=binarytoint(ans);ans[32]={0};
		printf("%lld\n",x);
		for(int i=0;i<32;i++){
			if(arr1[i]==1 && arr2[i]==1){
				ans[i]=1;
			}
		}x=binarytoint(ans);ans[32]={0};
		printf("%lld\n",x);
		for(int i=0;i<32;i++){
			if(arr2[i]==0){
				ans[i]=1;
			}
		}x=binarytoint(ans);ans[32]={0};
		printf("%lld\n",x);
		for(int i=0;i<32;i++){
			if(arr1[i]==1 || arr2[i]==0){
				ans[i]=1;
			}
		}x=binarytoint(ans);ans[32]={0};
		printf("%lld\n",x);
		for(int i=0;i<32;i++){
			if(arr1[i]==1)
				x++;
		}printf("%lld",x);
	}
}