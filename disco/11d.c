#include<stdio.h>
int flag=0; 
int tim[15][15]; 
void arra(int arr[],int k,int n,int m){ if(flag==1) return;
 if(k==n){ int ct=0,i,j; for(i=0;i<n;i++){ for(j=i+1;j<n;j++){ if(tim[arr[i]][arr[j]]==1) ct++; } }
  if(ct==m){ for(i=0;i<n;i++){ printf("%d ",arr[i]); } printf("\n"); flag=1; } 
  //printf("Y\n");
   } else{ int i; for(i=k;i<n;i++){ int temp=arr[k]; arr[k]=arr[i]; arr[i]=temp; arra(arr,k+1,n,m); temp=arr[k]; arr[k]=arr[i]; arr[i]=temp; } } } int main(){ int x,y,n,m; scanf("%d %d",&n,&m); int arr[n]; int i; for(i=0;i<n;i++) arr[i]=i+1; for(i=0;i<m;i++){ scanf("%d %d",&x,&y); tim[x][y]=1; } arra(arr,0,n,m); return 0; }