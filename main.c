/**
 *
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define BLOCKSIZE 4096

int main(int argc, char **argv) {
  int ifd, ofd;
  char ifd_str[8];
  char ofd_str[8];

  // Quick and dirty command line parsing
  if (argc == 2) { // Only input file, output stdout
    ofd = STDOUT_FILENO;
    if (strcmp(argv[1], "-") == 0) {
      ifd = STDIN_FILENO;
    } else {
      ifd = open(argv[1], O_RDONLY);
      //ofd = fopen (argv[1], "r");
      if (ifd < 0) {
        fprintf(stderr, "Opening input file failed\n");
        return -1;
      }
    }

  } else if (argc == 3) { // Both input and output file given
    if (strcmp(argv[1], "-") == 0) {
      ifd = STDIN_FILENO;
    } else {
      ifd = open(argv[1], O_RDONLY);
      if (ifd < 0) {
        fprintf(stderr, "Opening input file failed\n");
        return -1;
      }
    }
    if (strcmp(argv[2], "-") == 0) {
      ofd = STDOUT_FILENO;
    } else {
      ofd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
      if (ofd < 0) {
        fprintf(stderr, "Creating output file failed\n");
        return -1;
      }
    }
  } else {
    fprintf(stderr, "Usage: %s [input|-] [output|-]\n", argv[0]);
    return -1;
  }
  //printf("%d",ifd);

  if (ifd == STDIN_FILENO) {
    // create tempfile to store input from stdin
    int ifd_temp = open("as1_temp", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    char buf[129];
    long n;
    while ((n = read(ifd, buf, 128)) > 0) {
      buf[n] = '\0';  // re-terminate
      // printf("%s",buf);
      write(ifd_temp, buf, n);
      //write(ofd, buf, n);
    }

    // call to itself with new tempfile for input
    execl("./sovohj", "sovohj", "as1_temp", argv[2], NULL);
    close(ifd);
    close(ofd);
    return 0;
  }
  printf("%d",ifd);

  snprintf(ifd_str, 8, "%d", ifd);
  snprintf(ofd_str, 8, "%d", ofd);
  if (execl("./hello_world", "hello_world", ifd_str, ofd_str, NULL) != 0)
    perror("execv");

  close(ifd);
  close(ofd);

  return 0;
}
