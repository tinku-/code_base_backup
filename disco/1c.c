#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(){
	int n;
	int i=0,j=0;
	int a[51][51];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i][j]!=a[j][i]){
				a[j][i]=1;
				a[i][j]=1;
			}
		}
	}
	for(i=0;i<n;i++){
		a[i][i]=1;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			//if(i==(n-1) && j==(n-1))
			//	printf("%d",a[i][j]);
			//else
				printf("%d ",a[i][j]);
        }//if(i<n-1)
			printf("\n");
	}return 0;
}