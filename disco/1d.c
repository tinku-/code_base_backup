#include <stdio.h>
#include <math.h>
int tim=0;
int B[15][15];
void fun(int cruz[],int k,int n,int m){
	if(tim==1)
		return;
	if(k==n){
		int q=0,i,j;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(B[cruz[i]][cruz[j]]==1)
					q++;
			}
		}if(q==m){
			for(i=0;i<n;i++){
				printf("%d ",cruz[i]);
			}
			printf("\n");
			tim=1;
		}
	}else{
		int i;
			for(i=k;i<n;i++){
				int temp=cruz[k];
				cruz[k]=cruz[i];
				cruz[i]=temp;
				fun(cruz,k+1,n,m);
				temp=cruz[k];
				cruz[k]=cruz[i];
				cruz[i]=temp;
			}
	}
}int main(){
	int x,y,n,m,a,b=0;
	scanf("%d %d",&n,&m);
	int cruz[n];
	int i;
	for(i=0;i<n;i++)
		cruz[i]=i+1;
	for(i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		B[x][y]=1;
	}
	fun(cruz,0,n,m);
	return 0;
}