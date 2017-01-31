#include <stdio.h>
char s[100000];
char arr[1000];
int strlen()
{
	int i=0;
	while(s[i] != '\0')
		i++;
	return i;
}
int mod(int a,int m)
{
	if(a%m < 0)
		return (a%m+m);
	return a%m;
}
void sub3()
{
	int i=0;
	while(s[i] != '\0' && s[i] != '\n')
	{
		if(s[i] != ' ')
			s[i] = mod(s[i]-97-3,26)+97;
		i++;
	}
}	
void add3()
{
	int i=0;
	while(s[i] != '\0' && s[i] != '\n')
	{
		if(s[i] != ' ')
			s[i] = mod(s[i]-97+3,26)+97;
		i++;
	}
}
void reverse(int n)
{
   int i = 0;
   int j = n - 1;
   char temp;
   while (i < j) 
   {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
   }
}
void rev()
{
	int i=0,j=0,k=0	;
	for(i=0;i<=strlen();i++)
	{
		if(s[i] != ' ' && s[i] != '\0')
		{
			arr[j] = s[i];
			j++;
		}
		else
		{
			reverse(j);

			for(k=0;k<j;k++)
			{
				printf("%c",arr[k]);
				arr[k] = 0;
			}
			printf(" ");
			j=0;
		}
	}
}
int main()
{
	int i=0,code=0;
	gets(s);
	scanf("%d",&code);
	if(code == 1)
	{   
		
		sub3();
		rev();
		return 0;
	}
	else
	{
		
		add3();
		rev();
		return 0;
	}
}	