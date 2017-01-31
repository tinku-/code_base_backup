#include <stdio.h>
#include <stdlib.h>
int hash[10];
int count=0;
void insert(int hash[],int x)
{
	int probecnt=0,i=0;
	if(count >= 10)
	{
		printf("full");
		return;
	}
	count++;
	while(hash[(x%10+i)%10] != -999 && probecnt <= 10)
		{i++;probecnt++;}
	//printf("lol%d\n",i);
	if(hash[(x%10+i)%10] == -999)
		hash[(x%10+i)%10] = x;
}
void print(int hash[])
{
	int i=0;
	for(i=0;i<10;i++)
		printf("%d ",hash[i]);
	printf("\n");
}
int search(int hash[],int x)
{
	int i=0,probecnt = 0;
	while(hash[(x%10+i)%10] != x && probecnt <= 10)
		{i++;probecnt++;}
	if(hash[(x%10+i)%10] == x)
		return (x%10+i)%10;
	return -1;
}
void del(int hash[],int x)
{
	int temp=0,j=0,probecnt=0;
	int i = search(hash,x);
	hash[i] = -999;
	count--;
	while(probecnt <= 10)
	{
		probecnt++;j++;
		if(hash[(i+j)%10] != -999)
		{
			temp = hash[(i+j)%10];
			hash[(i+j)%10] = -999;
			count--;
			insert(hash,temp);
		}
	}

}
int main()
{
	int i=0;
	for(i=0;i<10;i++)
		hash[i] = -999;
	int n,x;
	while(1)
	{
		scanf("%d",&n);
		if(n == 1) // insert
		{
			scanf("%d",&x);
			insert(hash,x);
		}
		if(n == 2) // print
			print(hash);
		if(n == 3) // search
		{
			scanf("%d",&x);
			if(search(hash,x) != -1)
				printf("found at %d\n",search(hash,x));
			else
				printf("not found\n");
		}
		if(n == 4) // delete
		{
			scanf("%d",&x);
			del(hash,x);
			print(hash);
		}
	}

}