//
// Created by Otso Luukkanen on 19.10.2022.
//

#ifndef _MORSE_H_
#define _MORSE_H_
#include <stdio.h>

char* morseEncode(char x);
void morseCode(char* s, pid_t parentPid);
void readSendMorse(int ifd, int ofd, pid_t parentPid);

#endif //_MORSE_H_
