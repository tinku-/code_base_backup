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
int multi2(int x)
{
	int i = 0;
	for(i=0;i<100;i++)
		arr[i] = -1;
	arr[499] = 1;
	while(x)
	{
		multi(2);
		x--;
	}
	for(i=0;i<10;i++)
	{
		if(arr[490+i] != -1)
			printf("%d",arr[490+i] );
	}
	return 0;
}
int main()
{
	int a;
	scanf("%d",&a);
	multi2(a);
}

//done....................