#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	pid_t p;
	int status;
	p = fork();
	if(p < 0)
		perror("fork");
	else if(p == 0)
		printf("child\n");
	else
	{
		printf("parent\n");
		sleep(60);
	}
}