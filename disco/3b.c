#include <stdio.h>
// recursion with memoization.
long long unsigned int arr[51][51];
long long unsigned int combo(long long unsigned int x,long long unsigned int y)
{
	if(x<y)
	{
		arr[x][y] = 0;
		printf("ERROR");
		return 0;
	}
	if(x==y || y==0){
		arr[x][y]=1;
		return 1;
	}
	if(arr[x][y]!=-1)
		return arr[x][y];
	arr[x][y]=(combo(x-1,y-1)+combo(x-1,y));
	return arr[x][y];
}

int main(){
	long long unsigned int t,m,n,x,y,ans,temp,i,j;
	//printf("%lld",tim);
	scanf("%lld",&t);
	for(i=0;i<51;i++)
	{
		for(j=0;j<51;j++)
			arr[i][j]=-1;
	}

	while(t--)
	{
		scanf("%lld %lld",&m,&n);	
		x=m+n;
		y=m;
		ans=combo(x,y);
		printf("%lld\n",ans);
	}//printf("%d",sizeof(long long int));
	return 0;
}