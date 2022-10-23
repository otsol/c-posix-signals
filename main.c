#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <assert.h>

#include "morse.h"

static int sigpipe = 0;

static void sig_usr(int signo) {
  char ret = signo;
  write(sigpipe, &ret, 1);
}

int main(int argc, char **argv) {
  pid_t pid;
  int ifd, ofd, n;
  char buf[129];
  ifd = atoi(argv[1]);
  ofd = atoi(argv[2]);
  printf("Hello, World!\n");
  printf("Number of arguments %d\n", argc);

  printf("I'm open-exec2 and ofd is %d\n", ifd);
  printf("I'm open-exec2 and ofd is %d\n", ofd);

  pid = fork();
  if (pid == -1) {
    perror("<parent> Fork failed");
    return -1;
  }

  if (pid == 0) {
    // Only child process would come here
    printf("<child> I'm alive!\n");
    pid_t ppid = getppid();
    printf("%d", ppid);
    readSendMorse(ifd, ofd, ppid);
    //kill(ppid, SIGUSR1);
    printf("%d", getpid());
    exit(123);
  } else {
    // Only parent process would come here
    printf("<parent> Me too!\n");

    pid_t pid = getpid();
    printf("%d", pid);
    struct sigaction sig;



    int pipefd[2];

    assert(pipe(pipefd) == 0);
    sigpipe = pipefd[1];

    sigemptyset(&sig.sa_mask);
    sig.sa_flags = 0;
    sig.sa_handler = sig_usr;

    assert((sigaction(SIGUSR1, &sig, NULL)) == 0);
    assert((sigaction(SIGUSR2, &sig, NULL)) == 0);

    //int i = 0;
    //int queue[5];

    // init decoder
    struct Decoder dec = initDecoder(ofd);

    for (;;) {
      char mysignal;
      int res = read(pipefd[0], &mysignal, 1);
      // When read is interrupted by a signal, it will return -1 and errno is EINTR.
      if (res == 1) {
        if (mysignal == SIGUSR1) {
          printf("received SIGUSR1: %d\n", mysignal);
          //exit(123);
          //break;
          processMorse(&dec, mysignal);
        } else if (mysignal == SIGUSR2) {
          printf("received SIGUSR2\n");
          //break;
          processMorse(&dec, mysignal);
        }
      }
    }

  }


  //int c;
//    while((c=getc(ofd))!=EOF){
//            printf("%c",c);
//    }

//    while ((c = getc(ofd)) != EOF) {
//        printf("%c",c);
//    }
// seems like a stream cannot be passed or read from (fopen ...)
//    while ((n = read(ofd, buf, 128)) > 0) {
//        buf[n] = '\0';  // re-terminate
//        printf("%s",buf);
//        write(ofd, buf, n);
//    }
//    printf("%d",getpid());
//    return 0;
}
