#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
int main()
{
	char ch;
	FILE *f1;
	f1 = fopen("input4.txt","r");
	while((ch = getc(f1)) != EOF)
		printf("%c ",ch);
	fclose(f1);	