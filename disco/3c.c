#include <stdio.h>
long long int arr[1001];
long long int strln(char s[]){
	long long int i=0;
	while(s[i]!='\0')i++;
	return i;
} 
long long int Hi(long long int n){
	long long int x=1,k;
		for(k=0;k<(n-1);k++){
			if(arr[n-1-k]==arr[n-2-k])
				x++;
			else
				break;
		}
	if(n==x)
		return x;
	if(n==1)
		return 1;
	return 2*Hi(n-x)+x;
}
int main(){
	long long int t,n,j,i,temp,count;
	char s[51];
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(i=0;i<n;i++){
			scanf("%s",s);
			arr[i]=strln(s);
		}
		printf("%lld\n",Hi(n));
	}return 0;
}