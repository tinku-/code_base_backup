#include <stdio.h>
char c[100];
void comment()
{
	int i=0;
	while(c[i] != '\0')
	{
		if(c[i] == '/' && c[i+1] == '/')
		{
			while(c[i] != '\n')
			{
				c[i] = -10;
				i++;
			}
		}
		else if(c[i] == '/' && c[i+1] == '*')
		{ 
			while(c[i] != '*' && c[i+1] != '/')
			{
				printf("thiiis\n");
				printf("%c",c[i]);
				c[i] = -10;
				i++;
			}
			c[i] = -10;
			c[i+1] = -10;
		}
		i++;
	}
	i = 0;
	while(c[i] != '\0')
	{
		if(c[i] != -10)
			printf("%c",c[i]);
		i++;
	}
}
int main()
{
	scanf("%[^\t]s",c);
	comment();
	return 0;
	//ooe press tab and then press enter to stop taking input
}