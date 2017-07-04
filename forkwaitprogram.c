#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

#define MAX_COUNT 100
#define BUF_SIZE 100

void ChildProcess(char []);

void main(void)
{
	pid_t pid1,pid2,pid;
        int status;
        int i;
	char buf[BUF_SIZE];

	printf("\n***Parent is about to fork a process 1 ***\n");
	if((pid1 = fork())<0)
	{
		printf("Failed to fork process 1\n");
		exit(1);
	}
	else if(pid1 == 0)
		ChildProcess("First\n");
	
	printf("***Parent is about to fork a process 2 ***\n");
	if((pid2 = fork())<0)
	{
		printf("Failed to fork process 2\n");
		exit(1);
	}
	else if(pid2 == 0)
		ChildProcess("Second\n");

	sprintf(buf,"*** Parent enters waiting status ***\n");
	write(1,buf,strlen(buf));
	pid=wait(&status);
	printf("***Parent detects process %d is done ***\n",pid);
	pid=wait(&status);
	printf("***Parent detects process %d is done ***\n",pid);
        printf("***Parent exits ***\n");
	exit(0);
}

void ChildProcess(char *number)
{
	pid_t pid;
	int i;
	char buf[BUF_SIZE];

	pid = getpid();
	sprintf(buf,"%s child process starts (pid = %d)\n",number,pid);
	write(1,buf,strlen(buf));
	for(i=1;i<=MAX_COUNT;i++)
	{
		sprintf(buf,"%s child's output,value = %d\n",number,i);
		write(1,buf,strlen(buf)); 
	}
	sprintf(buf,"%s child(pid = %d) is about to exit\n",number,pid);
	write(1,buf,strlen(buf));
		exit(0);
}

