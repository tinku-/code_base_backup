#include <bits/stdc++.h>
using namespace std;
void swaper(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int a=1,b=66;
	swaper(&a,&b);
	cout<<a<<" "<<b;
}