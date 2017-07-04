//C program to demonstrate inter process communication using pipe
//child process writes data and parent process reads data
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>

void do_child(int data_pipe[])
{
  int c;
  int rc;
  close(data_pipe[1]);
  while((rc=read(data_pipe[0],&c,1))>0)
  {
    putchar(c);
  }
}

      void do_parent(int data_pipe[])
      {
        int c,rc;
        close(data_pipe[0]);
        while((c=getchar())>0)
        {
          rc=write(data_pipe[1],&c,1);
          if(rc==-1)
          {
            perror("PARENT : WRITE");
            close(data_pipe[1]);

          }
        }
          close(data_pipe[1]);
      }

      int main()
      {
        int data_pipe[2];
        int pid;
        int rc;
        rc=pipe(data_pipe);
        if(rc==-1)
        {
          perror("Error in Creating pipe");
        }

        pid=fork();
        switch(pid)
        {
          case -1: perror("Error in creating child process");
                    break;
          case 0: do_child(data_pipe);
                  break;
          default: do_parent(data_pipe);
                  break;
        }
        //return 0;
      }
