#include<stdio.h>

int main()
{
	char c1,c2,c;
	FILE * fp;

	int f1=0,f2=0;

	fp=fopen("mj.c","r");


	


	fclose(fp);

}




/*

#include<stdio.h>

int main(){
	char c1,c2;
	c1=' '; c2 =' ';

	int flag1=0,flag2=0;

	FILE *fp;

	fp = fopen("mj.c","r");

	while((c1=getc(fp)) != EOF){
     
        if(c1 == '('){
            c2 = getc(fp);
            if(c2 == '"'){
                flag1 =1;
				flag2 =1;
				printf("%c%c",c1,c2);
            }
            else{
                flag2 =1;
				printf("%c%c",c1,c2);
            }
        }

		if(c1 == '"'){
            c2 = getc(fp);
            if(c2 == ')'){
                flag1 =0;
				flag2 =1;
				printf("%c%c",c1,c2);
            }
            else{
                flag2 =1;
				printf("%c%c",c1,c2);
            }
        }
		if(c1 == '/' && flag1 ==0){
			c2 = getc(fp);
			if(c2 == '/'){
				while(getc(fp)!='\n'){}
				printf("\n");
			}
			else if(c2 == '*'){
				while(1){
				while(getc(fp) != '*');
				if(getc(fp) == '/'){
					break;
				}
				}
			}
			else
				printf("%c%c",c1,c2);
		}
		else if(flag2==0)
			printf("%c",c1);
		flag2=0;
	}
	fclose(fp);
	return 0;
}

*/