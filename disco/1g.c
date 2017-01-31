#include <stdio.h>
int main(){
	int i=0,j=0,k=0,m,n;
	int a[10001];
	scanf("%d",&m);
	scanf("%d",&n);
	for(i=1;i<10001;i++){
		if(i<=n)
			a[i]=0;
		else
			a[i]=1;
	}for(i=1;i<=m;i++){
		scanf("%d",&j);
		a[j]++;
	}for(i=1;i<10001;i++){
		if(a[i]>1){
			printf("INVALID\n");
			return 0;
		}
	}printf("VALID\n");
	return 0;
}