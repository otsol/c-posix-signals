//
// Created by Otso Luukkanen on 19.10.2022.
//

#ifndef _MORSE_H_
#define _MORSE_H_
#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <signal.h>
#include <string.h>

struct Decoder {
  char queue[10]; // stores morse chars
  int i; // index
  int ofd;
};

char* morseEncode(char x);
void morseCode(char *s, pid_t parentPid, int pipefd[2]);
void readSendMorse(int ifd, int ofd, pid_t parentPid, int pipefd[2]);
char morseDecode(char* s);
void processMorse(struct Decoder *decoder, char signal);
struct Decoder initDecoder(int ofd);

#endif //_MORSE_H_
