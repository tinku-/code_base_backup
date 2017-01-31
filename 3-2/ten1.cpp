#include <stdio.h>
#include <stdlib.h>
int main()
{
	char stack[100];
	int top=-1,i=0;
	char str[100];
	fgets(str,100,stdin);
	while(str[i] != '\n')
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			printf("%c",str[i]);
		if(str[i] == '^' || str[i] == '/' || str[i] == '*' || str[i] == '+' || str[i] == '-')
		{
			top++;
			stack[top] = str[i];
		}
		if(str[i] == ')')
		{
			printf("%c",stack[top]);
			top--;
		} 
		i++;
	}
	printf("%c",stack[top]);
	printf("\n");

}