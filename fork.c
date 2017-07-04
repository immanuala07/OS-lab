// C program to implement fork() system call
//parent process not ditingushed from the child process

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<limits.h>
#define MAX_COUNT 100
#define BUFF_SIZE 100

void main(void)
{
	pid_t pid;
	int i;
	char buf[BUFF_SIZE];

	fork();
	pid=getpid();
	for (i=1; i<=MAX_COUNT; i++)
	{
		sprintf(buf, "This Line is from pid %d, value =%d\n",pid,i);
		write(1,buf,strlen(buf));
	}
}
