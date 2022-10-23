/**
 * Mockup for ELEC-C7310 assignment 1.
 * This only writes data directly without doing a data transfer between processes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define BLOCKSIZE 4096

int main(int argc, char **argv) {
  int ifd, ofd;
  char ifd_str[8];
  char ofd_str[8];
  printf("%d", getpid());
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
    snprintf(ifd_str, 8, "%d", ifd);
    snprintf(ofd_str, 8, "%d", ofd);
    if (execl("./hello_world", "hello_world", ifd_str, ofd_str, NULL) != 0)
      perror("execv");
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
    snprintf(ifd_str, 8, "%d", ifd);
    snprintf(ofd_str, 8, "%d", ofd);
    if (execl("./hello_world", "hello_world", ifd_str, ofd_str, NULL) != 0)
      perror("execv");
  } else {
    fprintf(stderr, "Usage: %s [input|-] [output|-]\n", argv[0]);
    return -1;
  }

  // Allocate buffer
  char *buf = malloc(BLOCKSIZE);
  if (buf == NULL) return -1;
  while (1) {
    long s;
    s = read(ifd, buf, BLOCKSIZE);
    if (s < 0) return -1;
    if (s == 0) break; // input closed
    long r = 0;
    while (r < s) {
      long t = write(ofd, buf + r, s - r);
      if (t < 0) {
        return -1;
      }
      r += t;
    }
  }
  free(buf);
  close(ifd);
  close(ofd);

  return 0;
}
