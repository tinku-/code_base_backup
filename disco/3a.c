#include <stdio.h>
long long int dp[1001];
long long int block(long int n){
	if(n==0 || n==1 || n==2){
		dp[n]=1;
		return 1;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	dp[n]=block(n-1)+block(n-3);
	return dp[n];
}
int main(){
	int t,n,i;
	scanf("%d",&t);
	for(i=0 ; i<100 ; i++)
		dp[i] = -1;
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",block(n));
	}
	return 0;	
}