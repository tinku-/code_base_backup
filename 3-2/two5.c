#include <stdio.h>
#include <stdlib.h>
char temp [100];
char input[100];
char d[100][100];
int removespaces()
{
	int i=0,j=0;
	while(input[i] != '\0' && input[i] != '\n')
	{
		if(input[i] != ' ')
		{
			temp[j] = input[i];
			j++;
		}
		i++;
	}
	printf("%d\n",j);
	return j;
}
void encrypt(int key,int l)
{
	int i,j;
	for(i=0;i<key;i++)
	{
		for(j=0;j<l;j++)
		{
			if(j%key == i)
			{
				printf("%c",temp[j]);
			}
		}
	}
}
int main()
{
	int key =0;
	fgets(input,100,stdin);
	scanf("%d",&key);
	encrypt(key,removespaces());
	return 0;
}