#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	pid_t p;
	int so;
	p = fork();
	if(p < 0)
		perror("fork");
	else if(p == 0)
	{
		//child process
		printf("this is a child process and the PID is %d \n",getpid());
		sleep(5);
		printf("child done\n");
	}
	else
	{
		//parent process
		wait(&so);
		printf("this is a parent process and PID of child id %d\n",p );
		
		printf("parent done\n");
	}
	return 0;
}