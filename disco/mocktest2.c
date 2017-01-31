#include <stdio.h>
int main(){
	int n,sys=0;
	scanf("%d",&n);
	int a[1000][1000];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i][j]==a[j][i]){
				sys=1;
		    }else {
			    sys=0;
				break;
			}
		}if(sys==0){break;}
	}if(sys==0){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i][j]!=a[j][i]){
					sys=2;
			    }else {
			    	sys=0;
				    break;
			    }
			}if(sys==0){break;}
		}
	}if(sys==0){
		printf("nonsymmetric");
		printf("\n");
		a[1][2]=1;a[2][0]=1;
		}for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%d ",a[i][j]);
			}printf("\n");
		}
	}if(sys==1){
		printf("symmetric");
	}if(sys==2){
		printf("antisymmetric");
	}return 0;
}