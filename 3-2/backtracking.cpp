#include <stdio.h>
char arr[1000]={0};
void string(int n,int k)
{
	if(n<1)
	{
		printf("%s\n",arr);
		//int i = i+1;
	}
		
	else 
	{
		int j;
		for(j=97;j<97+k;j++)
		{
			arr[n-1] = j;
			string(n-1,k);
		}
	}
}
int main()
{
	int k,n;
	scanf("%d %d",&n,&k);
	string(n,k);
	return 0;
}