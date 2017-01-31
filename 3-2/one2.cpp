#include <stdio.h>
using namespace std;
#define MAX 1000000
char s1[MAX];
char s2[MAX];
char arr[MAX];
int equal(int a,int n1)
{
	int i;
	if(a != n1)
		return 0;
	for(i=0;i<a;i++)
	{
		if(arr[i] != s1[i])
			return 0;
	}
	return 1;
}
int main()
{
	
	int n1=0,n2=0,i=0,j=0,k=0,ans=0;
	//scanf("%[^\n]s",s1);scanf("%[^\n]s",s2);
	//gets(s1);gets(s2);
	fgets(s1,MAX,stdin);fgets(s2,MAX,stdin);
	while(s1[n1] != '\n')
		n1++;
	while(s2[n2] != '\n')
		n2++;
	for(i=0;i<=n2;i++)
	{
		if(s2[i] != ' ' && s2[i] != '\n')
		{
			arr[j] = s2[i];
			j++;
		}
		else
		{
			if(equal(j,n1) == 1)
				ans++;
			j=0;
		}
	}
	printf("%d",ans);
	return 0;
}
