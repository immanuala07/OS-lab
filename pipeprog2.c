//C program to demonstrate inter process communication using pipe
//child process writes data and parent process reads data
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>

int main()
{
  int fd[2],nbytes;
  pid_t childpid;
  char string[] = "Hello World!\n";
  char readbuffer[80];

  pipe(fd);

  if((childpid=fork())==-1)
  {
    perror("fork");
    exit(1);
  }

  if(childpid==0)
  {
    //child process closes up input side of pipe
    close(fd[0]);

    //send "String" through th output side of pipe
    write(fd[1],string,(strlen(string)+1));
    exit(0);
  }
  else
  {
    //Parent process closes up output side of pipe
      close(fd[1]);

    //read in astring from the pipe
    nbytes=read(fd[0],readbuffer,sizeof(readbuffer));
    printf("Recieved String %s",readbuffer);
  }
  return 0;
}
