#include <stdio.h>
int main(){
int n,m,q,i,p,zz;
scanf("%d %d %d",&n,&m,&q);
if(n<1||n>50||m>n*n||q<1||q>50){
    return 0;
}
int u[m],v[m];
for(i=0;i<m;i++){
    scanf("%d %d",&u[i],&v[i]);
    if(u[i]<1||u[i]>n||v[i]<1||v[i]>n){
        return 0;
    }
}
int t[q],j,r[q][n],a;
for(i=0;i<q;i++){
    scanf("%d",&t[i]);
    if(t[i]<1){
        return 0;
    }
    for(j=0;j<t[i];j++){
        scanf("%d",&r[i][j]);
        if(r[i][j]<1||r[i][j]>n){
            return 0;
        }
    }
}
int arrav[n+1][n+1],k;
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        arrav[i][j]=0;
    }
}
for(i=0;i<m;i++){
    arrav[u[i]][v[i]]=1;
}for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        if(arrav[i][j]==1){
            for(k=1;k<=n;k++){
                if(arrav[j][k]==1){
                    arrav[i][k]=1;
                }
            }
        }
    }
}for(i=0;i<q;i++){
        int sys[t[i]],answer[t[i]];
    for(j=0;j<t[i];j++){
        sys[j]=r[i][j];
    }
for(j=0;j<t[i];j++){
        for(k=0;k<t[i];k++){
            if(arrav[sys[j]][sys[k]]==1&&sys[j]!=0&&sys[k]!=0){
                sys[j]=0;
            }
        }
    }for (k = 0; k < t[i]; ++k)
    {
        for (j = k + 1; j < t[i]; ++j)
        {
            if (sys[k] > sys[j])
            {   a =  sys[k];
                sys[k] = sys[j];
                sys[j] = a;
            }
        }
    }
    //for(int i=0;i<n;i++)
    for(j=0;j<t[i];j++){
            if(sys[j]!=0)
        printf("%d ",sys[j]);
    }
    printf("\n");
}return 0;
}