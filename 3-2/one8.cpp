#include <stdio.h>
#define MAX 1000000
char arr[] = "goodbye";
char s[MAX];
int checker()
{
	int i=0,j=0;
	while(s[i] != '\0')
	{
		if(arr[j] == s[i])
			j++;
		i++;
	}
	if(j == 7)
		return 1;
	return 0;
}
int main()
{
	scanf("%[^\n]s",s);
	if(checker() == 1)
		printf("YES");
	else
		printf("NO");
	return 0;
}