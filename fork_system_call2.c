// Program to implement fork system call 2
// Parent process distinguished from the child process

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

#define MAX_COUNT 10

void ChildProcess(void);  //
void ParentProcess(void);

void main(void)
{
        pid_t pid;

        pid=fork();

        printf("Process id : %d\n",pid);
        if(pid==0)
            ChildProcess();
        else
            ParentProcess();
}
void ChildProcess(void)
{
    int i;
    for(i=0;i<=MAX_COUNT;i++)
        printf("This Line is from the Child, value = %d \n",i);
    printf("*** Child Process is Done\n");
}

void ParentProcess(void)
{
    int i;
    for(i=0;i<=MAX_COUNT;i++)
        printf("This Line is from the Parent, value = %d \n",i);
    printf("Parent process is Done\n");
}
