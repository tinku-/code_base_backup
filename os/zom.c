#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 

int main()
{
	pid_t p;
	int status;
	p = fork();
	if(p<0)
	{
		perror("fork");
		//exit(1);
	}
	else if(p == 0)
		printf("child process\n");
	else
	{
		printf("parent\n");
		sleep(60);
	}
}