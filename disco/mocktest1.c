#include <stdio.h>
int main(){
	int n,m,temp=0;
	scanf("%d %d",&n,&m);
	int a[101]={0};
	int b[101]={0};
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		a[temp]=1;
	}for(int i=0;i<m;i++){
		scanf("%d",&temp);
		b[temp]=1;
	}for(int i=0;i<=100;i++){
		if(a[i]==1 && b[i]==1){
			printf("%d ",i);
			temp=200;
		}
	}if(temp!=200){
		printf("NULL");
	}return 0;
}

7729932958