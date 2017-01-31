#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#define MAX 1000000
char s[MAX];
struct node
{
	char c;
	int count;
}*arr[256];
int main()
{
	int i,ct = 0,j,k;
	char str[MAX];
	//fgets(str,50,stdin);
	scanf("%[^\n]s",str);
	for(i=0;str[i] != '\0';i++)
	{
		int flag=0;
		for(k=0;k<ct;k++)
		{
				if(arr[k]->c==str[i])
				{
					arr[k]->count++;
					flag=1;
					break;
				}
		}
		if(flag==0)
		{
			struct node* nn;
			nn = (node*) malloc(sizeof(node));
			arr[ct] = nn;
			arr[ct]->c=str[i];
			arr[ct]->count=1;
			ct++;
		}	
	}
	for(i=0;i<ct;i++)
		printf("%c %d\n",arr[i]->c,arr[i]->count);
}