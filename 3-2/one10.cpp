#include <stdio.h>
int arr[500];
void multi(int y)
{
	int i=0,carry=0,temp=0;
	while(arr[500-1-i] != -1)	
	{	
		temp = arr[500-1-i]*y+carry;
		arr[500-1-i] = temp%10;
		carry = temp/10;
		i++;
	}
	while(carry != 0)
	{
		arr[500-1-i]=carry%10;
		carry = carry/10;
		i++;
	}
}
void fact(int x)
{
	int i=0,carry=0,temp=0,su=0;
	for(i=0;i<500;i++)
		arr[i] = -1;
	i=0;su = x-1;
	while(x)
	{
		arr[500-1-i] = x%10;
		x = x/10;
		i++;
	}
	while(su)
	{
		multi(su);
		su--;
	}
	for(i=0;i<500;i++)
	{	
		if(arr[i] != -1)
			printf("%d",arr[i]);
	}
}
int main()
{
	int a;
	scanf("%d",&a);
	fact(a);
	return 0;
}
//done..............