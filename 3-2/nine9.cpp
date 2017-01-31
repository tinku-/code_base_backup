#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int arr[10] = {0};
int tot=0;
int insert(int x)
{
	if(tot == 10)
		{printf("table full\n");return 0;}
	int i=0;
	while((arr[(x%10 + i*i)%10] != 0 && arr[(x%10 + i*i)%10] != -1))
		i++;
	arr[(x%10 + i*i)%10] = x;
	tot++;
	return 0;
}	
void print()
{
	if(tot == 0)
		{printf("empty\n");return ;}
	int i=0;
	for(i=0;i<10;i++)
	{
		if(arr[i] != -1 && arr[i] != 0)
			printf("%d ",arr[i]);
	}
	printf("\n");
	return;
}
int search(int x)
{
	int i=0,flag=0,count=0;
	if(tot == 0)
		{printf("empty\n");return 0;}
	while(arr[(x%10 + i*i)%10] != 0 && count <= 10)
	{	
		if(arr[(x%10 + i*i)%10] == x)
		{
			flag++;
			break;
		}
		count++;
		i++;
	}
	if(flag != 1)
		printf("not found\n");
	else
		printf("found\n");
	return 0;
}
int del(int x)
{
	int i=0,flag=0,count=0;
	if(tot == 0)
		{printf("empty\n");return 0;}
	while(arr[(x%10 + i*i)%10] != 0 && count <= 10)
	{	
		if(arr[(x%10 + i*i)%10] == x)
		{
			arr[(x%10 + i*i)%10] = -1;
			flag++;
			tot--;
			//break;
		}
		count++;
		i++;
	}
	if(flag != 1)
		printf("not found\n");
	return 0;
}
int main()
{
	int n,x;
	while(1)
	{
		scanf("%d",&n);
		if(n == 1)
		{
			scanf("%d",&x);
			insert(x);
		}
		if(n == 2)
		{
			print();
		}
		if(n == 3)
		{
			scanf("%d",&x);
			search(x);
		}
		if(n == 4)
		{
			scanf("%d",&x);
			del(x);
		}
		if(n == 5)
			break;
	}
}