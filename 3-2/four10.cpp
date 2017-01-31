#include <stdio.h>
#define MAX 1000000
using namespace std;
char arr[MAX];
int reverse(int start,int end)
{
	int var = end;
	char temp;
	while(start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
	return var+2;
}
int main()
{
	int i=0,start=0,end=0,n1=0;
	fgets(arr,MAX,stdin);
	while(arr[n1] != '\n')
		n1++;
	while(arr[end-1] != '\n')
	{
		if(arr[end] == ' ' || arr[end] == '\n')
		{
			start = reverse(start,end-1);
		}
		end++;
	}
	for(i=n1-1;i>=0;i--)
		printf("%c",arr[i]);
	printf("\n");
	return 0;
}