#include <stdio.h>
int strlen(char*str){
	char*p=str;
	while(*str)++str;
	return str-p;
}
void strcpy(char*dest , char*src){
	char* save = dest;
	while(*dest++=*src++);
}
void strcat(char*str2 , char*str1){
	char *save = str2;
	while(*str1)
	++str1;
	while(*str1++=*str2++);
}
int strend(char *s, char*t){
	char *q=t;
	char *p=s;
	while(*t) ++t;
	while(*s) ++s;
	s-=(t-q);
	for(;*q;s++,q++){
		if(*s!=*q)
		return 0;
	}
	return 1;
}
void reverse (char *original){
	int i,j;
	for(i=0,j=strlen(original)-1;i<j;i++,j--){
		char temp = original[i];
		original[i]=original[j];
		original[j]=temp;
		}
	}
	int main(){
		// write any code as you please using above functions//
	}
