#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <assert.h>
#include <time.h>
#include <fcntl.h>

#include "morse.h"

static int sigpipe = 0;

static void sig_usr(int signo) {
  char ret = signo;
  write(sigpipe, &ret, 1);
}

int main(int argc, char **argv) {
  pid_t pid;
  int ifd, ofd;

  // str to int
  ifd = atoi(argv[1]);
  ofd = atoi(argv[2]);


  // pipe for logging
  int log_pipe[2];
  char buf[1025]; // buffer for reading from pipe
  if (pipe(log_pipe) < 0)
    exit(1);
  // open log file
  int log_ofd = open("as1_log", O_WRONLY | O_CREAT | O_TRUNC, 0666);

  char time_str[64]; // string for storing formatted time string
  int len; // len for snprintf
  // log string for writing to pipe
  char log_str[128];

  // time for logging
  time_t rawtime;
  struct tm * timeinfo;



  pid = fork();
  if (pid == -1) {
    perror("<parent> Fork failed");
    return -1;
  }

  if (pid == 0) {
    // Only child process would come here

    // copy pipe fd
    // dup(log_pipe[1]);

    // write to log pipe
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(time_str, 64, "%F %T", timeinfo);
    len = snprintf(log_str, 128, "[%s] Child: PROCESS STARTED -------------\n", time_str);
    write(log_pipe[1], log_str, len);
    close(log_pipe[0]);

    // Pass input file fd, output file fd parent process ID to morse library
    pid_t ppid = getppid();
    readSendMorse(ifd, ppid, NULL);
    write(log_pipe[1], "hello", 6);


    close(ifd);
    close(ofd);
    exit(123);
  } else {
    // Only parent process would come here

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    strftime(time_str, 64, "%F %T", timeinfo);
    len = snprintf(log_str, 128, "[%s] Parent: PROGRAM STARTED ----------------------\n", time_str);
    write(log_pipe[1], log_str, len);


    // signal handler struct
    struct sigaction sig;

    // internal pipe for handling received signals in order
    int pipefd[2];

    assert(pipe(pipefd) == 0);
    sigpipe = pipefd[1];

    sigemptyset(&sig.sa_mask);
    sig.sa_flags = 0;
    sig.sa_handler = sig_usr;

    // these signal are handled by sig_usr
    assert((sigaction(SIGUSR1, &sig, NULL)) == 0);
    assert((sigaction(SIGUSR2, &sig, NULL)) == 0);
    assert((sigaction(SIGALRM, &sig, NULL)) == 0);
    assert((sigaction(SIGCHLD, &sig, NULL)) == 0);

    // init decoder
    struct Decoder dec = initDecoder(ofd);
    // nanosleep wait which allows child to initialize itself
    nanosleep((const struct timespec[]){{0, 50000000L}}, NULL);
    kill(pid, SIGUSR1);
    for (;;) {
      char mysignal;
      // read one signal from signal pipe
      long res = read(pipefd[0], &mysignal, 1);
      // When read is interrupted by a signal, it will return -1 and errno is EINTR.
      if (res == 1) {
        if (mysignal == SIGUSR1) {
          processMorse(&dec, mysignal);
        } else if (mysignal == SIGUSR2) {
          processMorse(&dec, mysignal);
        } else if (mysignal == SIGALRM) {
          processMorse(&dec, mysignal);
        } else if (mysignal == SIGCHLD) {
          // if child process terminates, it sends SIGCHLD to parent
          // this happens when EOF is read in child
          // break the signal reading endless loop and start quitting the program
          break;

        }
        // write to log pipe
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );

        strftime(time_str, 64, "%F %T", timeinfo);
        len = snprintf(log_str, 128, "[%s] Parent: Received %d signal\n", time_str,mysignal);
        write(log_pipe[1], log_str, len);
        // read from pipe and write to log file
        long n = read(log_pipe[0], buf, 1024);
        write(log_ofd, buf, n);
        // notify child process that one signal has been processed and next can be sent
        kill(pid, SIGUSR1);
      }
    }
    // close signal pipe
    close(pipefd[0]);
    close(pipefd[1]);

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    strftime(time_str, 64, "%F %T", timeinfo);
    len = snprintf(log_str, 128, "[%s] Parent: Closed signal pipe\n", time_str);
    write(log_ofd, log_str, len);

  }

}
