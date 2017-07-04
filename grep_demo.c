#include<stdio.h>
#include<string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char fline[100];
    char *newline;
    int i, count = 0, occ = 0;

    // for starters, ensure that enough arguments were passed:
    if (argc < 3) {
      printf("Not enough command line parameters given!\n");
      return 3;
    }

    fp = fopen(argv[1], "r");
    // fopen will return if something goes wrong.  In that case errno will
    // contain the error code describing the problem (could be used with
    // strerror to produce a user friendly error message
    if (fp == NULL) {
      printf("File could not be opened, found or whatever, errno is %d\n",errno);
      return 3;
    }


    while (fgets(fline, 100, fp) != NULL) {
        count++;
        if (newline = strchr(fline, '\n'))
            *newline = '\0';
        if (strstr(fline, argv[2]) != NULL) {
            // you probably want each found line on a separate line,
            // so I added \n
            printf("%s %d %s\n", argv[1], count, fline);
            occ++;
        }  // it's good practice to end your last print in \n
    }    // that way at least your command prompt stars in the left column


    printf("\n Occurence= %d\n", occ);

    return 1;
}
