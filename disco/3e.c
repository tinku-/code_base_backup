#include <stdio.h> 
long long int max(long long int a,long long int b){
	if(a>=b)
		return a;
	else
		return b;
}
long long int strln(char s[]){
	long long int i=0;
	while(s[i]!='\0')i++;
	return i;
} 	
int main(){
	char c1[51],c2[51];
	long long int t,n,s,temp=0,temp2=0;
	scanf("%lld",&t);
	while(t--){
		scanf("%s %s",c1,c2);
		for(s=1;s<26;s++)
			for(n=1;n<=5;n++)
			{
				if((c1[0]+s*n-'a')%26==(c2[0]-'a'))
				{
					temp=max(s,temp);
					temp=s;
					temp2=n;
				}

			}
		printf("%lld %lld\n",temp,temp2);	
	}
	return 0;
}