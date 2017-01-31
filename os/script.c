#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <string.h>

int main()
{
	
	{
		int s;
		if(fork() == 0)
		{
			if(execlp("pwd","pwd",NULL) == -1)
				perror("exit");
			exit(1);
		}
		else
 			wait(&s);
	}
}