#include <stdio.h>
int main(){
int m,n,i,j,k;
scanf("%d %d",&m,&n);
char x[n],y[n],c,p,ww,zz;
int penelopecruz[m+1][m+1];
getchar();
for(i=0;i<n;i++){
    x[i]=getchar();
    c=getchar();
    y[i]=getchar();
    p=getchar();
}for(i=1;i<=m;i++){
    for(j=1;j<=m;j++){
        penelopecruz[i][j]=0;
    }
    penelopecruz[i][i]=1;
}

for(i=0;i<=n;i++){
    penelopecruz[x[i]-64][y[i]-64]=1;
    penelopecruz[y[i]-64][x[i]-64]=1;
}for(i=1;i<=m;i++){
    for(j=1;j<=m;j++){
            for(k=1;k<=m;k++){
                if(penelopecruz[i][j]==1&&penelopecruz[j][k]==1){
                    penelopecruz[i][k]=1;
                }
            }
        }
}char z[m];
int answer=0,h=0,count =0;
for(i=1;i<=m;i++){
        count=0;
    for(j=1;j<=m;j++){
        if(penelopecruz[i][j]==1){
             count=0;
             int nt=0;
             for(k=0;k<m;k++){
                if(64+i==z[k] || 64+j==z[k]){
                    count++;
                }if(64+j!=z[k]){
                    nt++;
                }
             }if(nt==m&&i!=j){
                z[h]=64+j;
                h++;
             }if(count==0){
                    if(i!=j){
                z[h]=64+i;
                z[h+1]=64+j;
                h=h+2;
                }else{
                z[h]=64+i;
                h++;
                }
                answer++;
             }
        }
    }
}
printf("%d",answer);
return 0;
}
