#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
 	pid_t pid;
 	int pfd[2];
 	int s;
 	pipe(pfd);
 	pid = fork();
 	if (pid == 0) {
 		dup2(pfd[1], 1);
 		close(pfd[0]);
 		close(pfd[1]);
 		if(execlp("ls","ls",NULL) == -1)    /* first child runs “ls” */
 			perror("execlp ls");
 	} else {
 		if (fork() == 0) {
 			dup2(pfd[0], 0);
 			close(pfd[0]);
 			close(pfd[1]);
 			if(execlp("wc","wc","-l",NULL) == -1)  /*second child runs wc” */
 				perror("execlp wc");
 		} else {
 			close(pfd[0]);
 			close(pfd[1]);
 			wait(&s);
 			wait(&s); /* need to wait for both the children */
 		}
 	}
}