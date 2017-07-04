//This program cretes two child processes displaying some lines
//The parent waits until all child processes are done and exits

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX_COUNT 10
#define BUF_SIZE 100

void childProcess(char []); //Child prototype

void main()
{
  pid_t pid1,pid,pid2;
  int status,i;
  char buf[BUF_SIZE];

    printf("*** Parent is about to fork process 1 ***\n");
      if((pid1=fork())<0)
      {
        printf("Failed to fork process 1\n");
        exit(1);
      }
      else if(pid1==0)
      {
        childProcess("First");
      }

      printf("*** Parent is about to fork process 2 ***\n");
      if((pid2=fork())<0)
      {
        printf("Failed to fork process 2\n");
        exit(1);
      }
      else if(pid2==0)
      {
        childProcess("Second");
      }

                sprintf(buf,"*** Parent enters waiting status ......\n");
                write(1,buf,strlen(buf));
                pid=wait(&status);
                sprintf(buf,"*** Parent detects process %d was done ***\n",pid);
                write(1,buf,strlen(buf));
                pid=wait(&status);
                printf("*** Parent detects pocess %d id done ***\n",pid);
                printf("*** Parent exits ***\n");
                exit(0);
}

                              void childProcess(char *number)
                              {
                                pid_t pid;
                                int i;
                                char buf[BUF_SIZE];

                                pid =getpid();
                                sprintf(buf,"%s child process starts (pid = %d)\n",number,pid);
                                write(1,buf,strlen(buf));
                                for(i=1;i<=MAX_COUNT;i++)
                                {
                                  sprintf(buf,"%s child's output, value = %d\n",number,i);
                                  write(1,buf,strlen(buf));
                                }

                                sprintf(buf,"%s child (pid = %d) is about to exit\n",number,pid);
                                write(1,buf,strlen(buf));
                                exit(0);
                              }
