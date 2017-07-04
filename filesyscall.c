//program to implement unix I/O system calls- open() close() read() write() lseek()

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	int ch,fd1;
	char txt[60];
	do
	{
		printf("\n FILE MENU OPERATION");
		printf("\n==================");
		printf("\n1. File creation");
		printf("\n2. File reading");
		printf("\n3. Move File Pointer");
		printf("\n0. Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
			fd1=open("stud3.txt",O_CREAT|O_WRONLY|O_TRUNC);
			printf("\n File created successfully...");
			printf("\n Enter the information in the file: \n");
			scanf("%s",txt);
			write(fd1,txt,strlen(txt));
			printf("\n Information written successfully:");
			close(fd1);
			printf("\n file closed");
			break;
		
			case 2:
			printf("\n Enter the file name to open: ");
			scanf("%s",txt);
			fd1=open(txt,O_RDONLY);
			printf("\n Information about the file: ");
			while(read(fd1,txt,50)>0)
				write(STDOUT_FILENO,txt,5);
			close(fd1);
			break;
			
			case 3:
			printf("\n Enter the file name to open: ");
			scanf("%s",txt);
			fd1=open(txt,O_RDONLY);
			lseek(fd1,5,SEEK_SET);
			printf("\n Information about the file: ");
			while(read(fd1,txt,50)>0) 
				write(STDOUT_FILENO,txt,5);
			close(fd1);
			break;	
		
			case 0: exit(0);
			break;
			
			default: printf("\n Invalid Choice!!!!!!!");	
			break;
		}//end of switch
	}while(ch!=0);//end of while
}

//SEEK_SET for setting in beginning
