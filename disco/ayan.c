#include <stdio.h>
int main()
{
	int v,i,sum=0;
	int arr[20000];
	scanf("%d",&v);
	for(i=0;i<v;i++)
	{
		scanf("%d",&arr[i]);		
		sum=sum+arr[i];
	} 
	if(sum%2==1)
	{
		printf("invalid"); 
		return 0;
	}
	if(sum%2==0)
	{
		if(sum == v*(v-1))
		{
			printf("complete");
		    return 0;
		}
		if(sum == 2*(v-1))
		{
			printf("star"); 
			return 0;
		}
		if(sum == 2*v)
		{
			printf("cycle"); 
			return 0;
		}
		if(sum == (v-1)*4)
		{
			printf("wheel"); 
			return 0;
		}
	}
	printf("none");
	return 0;
}