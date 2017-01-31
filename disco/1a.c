#include <stdio.h>
int n; 

int fun(int array[n-1][n-1]){
int i,j,k,f=1;
for(i=0;i<n-1;i++){
	for(j=0;j<n-1;j++){
		for(k=0;k<n-1;k++){
			if(array[i][j]==1){
			 if((array[i][i]==0) || (array[j][j]==0) || (array[j][i]==0))
				f=0;
			}if((array[i][k]==1) && (array[k][j]==1) && (array[i][j]==0))
				f=0;
			}
		}
	}
	return f;
}
int main(){
    int m,i,x,y,j,p=1,q=1,r=1;
	scanf("%d",&n);
	scanf("%d",&m);
	int a[n][n],c[n-1][n-1];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;
	for(i=0;i<m;i++){
		scanf("%d %d",&x, &y);
		a[x-1][y-1]=1;
	}
	int r=0,s=0,t=0,k;
	//for(int i=0;i<n;i++)
	for(i=0; i<n; i++){
		r=0;
		for(j=0; j<n; j++){
			if(j==i)
			continue;
			s=0;
			for(k=0; k<n; k++){
				if(k==i)
				continue;
				c[r][s] = a[j][k];
				s++;
			}
			r++;
		}if(fun(c))
			t=t+1;
		}printf("%d\n",t);
		return 0;
 }

