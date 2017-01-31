#include <stdio.h>
int main(){
int M,N,i,j,k;
scanf("%d %d",&M,&N);
if(M<1||M>26||N<0||N>20||N>M*M){
    return 0;
}
char x[N],y[N];
int matrix[M+1][M+1];
char c,p;
getchar();
for(i=0;i<N;i++){
    x[i]=getchar();
    c=getchar();
    y[i]=getchar();
    p=getchar();
    if(x[i]<65||x[i]>64+M||y[i]<65||y[i]>64+M){
        return 0;
    }
    //printf("%c %c",x[i],y[i]);
}
for(i=1;i<=M;i++){
    for(j=1;j<=M;j++){
        matrix[i][j]=0;
    }
    matrix[i][i]=1;
}
for(i=0;i<=N;i++){
    matrix[x[i]-64][y[i]-64]=1;
    matrix[y[i]-64][x[i]-64]=1;
    //printf("%c %c \n%c %c \n",x[i],y[i],y[i],x[i]);
}
for(i=1;i<=M;i++){
    for(j=1;j<=M;j++){
            for(k=1;k<=M;k++){
                if(matrix[i][j]==1&&matrix[j][k]==1){
                    matrix[i][k]=1;
                }
            }
    }
}
/*for(i=1;i<=M;i++){
    for(j=1;j<=M;j++){
        printf("%d ",matrix[i][j]);
    }
    printf("\n");
}*/
char z[M];
int num=0;
int h=0,count =0;;
for(i=1;i<=M;i++){
        count=0;
    for(j=1;j<=M;j++){
        if(matrix[i][j]==1){
             //printf("%c %c ",64+i,64+j);
             count=0;
             int mint=0;
             for(k=0;k<M;k++){
                if(64+i==z[k]||64+j==z[k]){
                    count++;
                }
                if(64+j!=z[k]){
                    mint++;
                }
             }
             if(mint==M&&i!=j){
                z[h]=64+j;
                h++;
             }
             if(count==0){
                    if(i!=j){
                z[h]=64+i;
                z[h+1]=64+j;
                h=h+2;
                }else{
                z[h]=64+i;
                h++;
                }
                //printf("%c %c ",64+i,64+j);
                num++;
             }
        }
    }
   // printf("\n");
}
//for(i=0;i<M;i++){
  // printf("%c",z[i]);
//}
printf("%d",num);
//done
return 0;
}