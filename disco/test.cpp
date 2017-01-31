#include <stdio.h>
//18446744073709551612
//4294967292
long long int binarytoint(long long int arr[32]){
	unsigned long long int z=1;
	unsigned long long int sum=0;
	for(int i=0;i<32;i++){
		sum=sum+arr[31-i]*z;
		z=z*2;
		printf("%llu  %llu\n",z,sum);
	}return sum;
}
int main(){
	unsigned long long int t;
	long long int a[32]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0};
	t=binarytoint(a);
	printf("%llu",t);
}
2
31 23
43 21


KbKXRZ