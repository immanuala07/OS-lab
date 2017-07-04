//c program Forking separate Process
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
pid_t pid;

/*fork a child process*/
pid = fork();

if(pid < 0)
{ /*error occured*/
fprintf(stderr,"fork failed");
return 1;
}
else if (pid == 0)
{/*child process*/
execlp("/bin/ls","ls",NULL);
}
else{ /*parent process */
/*parent will wait for the child to complete */
wait(NULL);
printf("child complete");
}
return 0;
}
