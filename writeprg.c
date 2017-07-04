//c program to demonstrate write I/O system call

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

main()
{
  int fd, sz;

  fd = open("out3", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd < 0) { perror("r1"); exit(1); }

  sz = write(fd, "cs360\n", strlen("cs360\n"));

  printf("called write(%d, \"cs360\\n\", %d).  it returned %d\n", fd, strlen("cs360\n"), sz);

  close(fd);
}