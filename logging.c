//
// Created by Otso Luukkanen on 23.10.2022.
//

#include "logging.h"
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

void logger(const char* tag, const char* message) {
  time_t now;
  time(&now);
  //printf("[%s] [%s]: %s\n", ctime(&now), tag, message);
}

int main(int argc, char **argv) {
  pid_t pid;
  int ifd, ofd;
  ofd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
  // str to int
  ifd = atoi(argv[1]);
  ofd = atoi(argv[2]);

  char buf[129];
  long n;

  while(1) {
    n = read(ifd, buf, 128);
    write(ofd, buf, n);
  }

}