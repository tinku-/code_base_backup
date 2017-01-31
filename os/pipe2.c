#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h>
int main()
{
	int pfds[2];
	int buf;
	pipe(pfds);
	int s;
	int val;
	if(!fork())
	{
		close(pfds[0]);
		
		val = 6;
		printf(" CHILD: writing to the pipe\n");
 		write(pfds[1],&val,sizeof(val));
 		printf(" CHILD: exiting\n");
 		
 		exit(0);
	}
	else
	{
		close(pfds[1]);
		printf(" PARENT: reading from pipe\n");
		read(pfds[0],&val,sizeof(val));
		printf("PARENT: read \"%d\"\n", val);
		wait(NULL);
	}
	return 0;
}