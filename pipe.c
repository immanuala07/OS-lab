#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
int main(int argc, char *argv[] )
{
int fd[2],nbytes;
pid_t childpid;
//char argv[0][]=argv[0];
char readbuffer[80];

pipe(fd);
if((childpid = fork())==-1)
{
perror("fork");
exit(1);
}
//fd[0]=parent process,fd[1]=child process
if(childpid ==0)
{
close(fd[0]);

write(fd[1],argv[1] ,(strlen(argv[1])+1));
exit(0);
}

else
{
close (fd[1]);//fd[1] for read
nbytes=read(fd[0],readbuffer,sizeof(readbuffer));
printf("Received string:%s\n",readbuffer);
}
return(0);
}
