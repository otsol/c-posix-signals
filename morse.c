//
// Created by Otso Luukkanen on 19.10.2022.
//
// CPP program to demonstrate Morse code


#include <stdlib.h>
#include <time.h>
#include "morse.h"

// function to encode a alphabet as
// Morse code
char *morseEncode(char x) {
  char *s = malloc(2);
  // refer to the Morse table
  // image attached in the article
  switch (x) {
    case 'a':return ".-";
    case 'b':return "-...";
    case 'c':return "-.-.";
    case 'd':return "-..";
    case 'e':return ".";
    case 'f':return "..-.";
    case 'g':return "--.";
    case 'h':return "....";
    case 'i':return "..";
    case 'j':return ".---";
    case 'k':return "-.-";
    case 'l':return ".-..";
    case 'm':return "--";
    case 'n':return "-.";
    case 'o':return "---";
    case 'p':return ".--.";
    case 'q':return "--.-";
    case 'r':return ".-.";
    case 's':return "...";
    case 't':return "-";
    case 'u':return "..-";
    case 'v':return "...-";
    case 'w':return ".--";
    case 'x':return "-..-";
    case 'y':return "-.--";
    case 'z':return "--..";
    case '1':return ".----";
    case '2':return "..---";
    case '3':return "...--";
    case '4':return "....-";
    case '5':return ".....";
    case '6':return "-....";
    case '7':return "--...";
    case '8':return "---..";
    case '9':return "----.";
    case '0':return "-----";
    default:
      /* gives {\0, \0} */
      s[0] = x;
      s[1] = '\0';
      //return "-----";
      return s;
      //return "Found invalid character: ";
      //exit(0);
  }
}

char morseDecode(char *s) {
  if (strcmp(s, ".-") == 0) {
    return 'a';
  } else if (strcmp(s, "-...") == 0) {
    return 'b';
  } else if (strcmp(s, "-.-.") == 0) {
    return 'c';
  } else if (strcmp(s, "-..") == 0) {
    return 'd';
  } else if (strcmp(s, ".") == 0) {
    return 'e';
  } else if (strcmp(s, "..-.") == 0) {
    return 'f';
  } else if (strcmp(s, "--.") == 0) {
    return 'g';
  } else if (strcmp(s, "....") == 0) {
    return 'h';
  } else if (strcmp(s, "..") == 0) {
    return 'i';
  } else if (strcmp(s, ".---") == 0) {
    return 'j';
  } else if (strcmp(s, "-.-") == 0) {
    return 'k';
  } else if (strcmp(s, ".-..") == 0) {
    return 'l';
  } else if (strcmp(s, "--") == 0) {
    return 'm';
  } else if (strcmp(s, "-.") == 0) {
    return 'n';
  } else if (strcmp(s, "---") == 0) {
    return 'o';
  } else if (strcmp(s, ".--.") == 0) {
    return 'p';
  } else if (strcmp(s, "--.-") == 0) {
    return 'q';
  } else if (strcmp(s, ".-.") == 0) {
    return 'r';
  } else if (strcmp(s, "...") == 0) {
    return 's';
  } else if (strcmp(s, "-") == 0) {
    return 't';
  } else if (strcmp(s, "..-") == 0) {
    return 'u';
  } else if (strcmp(s, "...-") == 0) {
    return 'v';
  } else if (strcmp(s, ".--") == 0) {
    return 'w';
  } else if (strcmp(s, "-..-") == 0) {
    return 'x';
  } else if (strcmp(s, "-.--") == 0) {
    return 'y';
  } else if (strcmp(s, "--..") == 0) {
    return 'z';
  } else if (strcmp(s, "-.--") == 0) {
    return 'y';
  } else if (strcmp(s, ".----") == 0) {
    return '1';
  } else if (strcmp(s, "..---") == 0) {
    return '2';
  } else if (strcmp(s, "...--") == 0) {
    return '3';
  } else if (strcmp(s, "....-") == 0) {
    return '4';
  } else if (strcmp(s, ".....") == 0) {
    return '5';
  } else if (strcmp(s, "-....") == 0) {
    return '6';
  } else if (strcmp(s, "--...") == 0) {
    return '7';
  } else if (strcmp(s, "---..") == 0) {
    return '8';
  } else if (strcmp(s, "----.") == 0) {
    return '9';
  } else if (strcmp(s, "-----") == 0) {
    return '0';
  }

/* more else if clauses */
  else /* default: */
  {
    return 206; // random ASCII char ╬
  }

}

void morseCode(char *s, pid_t parentPid) {
  // character by character print
  // Morse code
  char morseChar[8];
  for (int i = 0; s[i]; i++) {

    printf("%s", morseEncode(s[i]));
    snprintf(morseChar, 8, "%s", morseEncode(s[i]));
    for (int j = 0; morseChar[j]; j++) {
      //sleep(1);
      //nanosleep((const struct timespec[]){{0, 10000000L}}, NULL);
      //printf("morse char: %c", s[j]);
      if (morseChar[j] == '.') {
        kill(parentPid, SIGUSR1);
      } else if (morseChar[j] == '-') {
        kill(parentPid, SIGUSR2);
      } else continue;
    }
    //sleep(1);
    //nanosleep((const struct timespec[]){{0, 10000000L}}, NULL);
    kill(parentPid, SIGALRM); // end of one text char
  }
  //char* morseCode = morseEncode (s[])

}

void readSendMorse(int ifd, int ofd, pid_t parentPid) {
  char buf[129];
  long n;
  while ((n = read(ifd, buf, 128)) > 0) {
    buf[n] = '\0';  // re-terminate
    // printf("%s",buf);
    morseCode(buf, parentPid);
    //write(ofd, buf, n);
  }
  //sleep(1);

}

struct Decoder initDecoder(int ofd) {
  struct Decoder ret = {.i = 0, .ofd = ofd};
  ret.queue[5] = '\n';
  return ret;
}

void processMorse(struct Decoder *decoder, char signal) {
  if (signal == SIGUSR1 || signal == SIGUSR2/* || signal == SIGALRM*/) {
    printf("Process morse: %d\n", signal);
    if (signal == SIGUSR1) {
      decoder->queue[decoder->i] = '.';
    } else /*if (signal == SIGUSR2)*/ {
      decoder->queue[decoder->i] = '-';
    }
    decoder->queue[decoder->i + 1] = '\0'; // close string
    decoder->i = decoder->i + 1; // next index
//    char symbol = morseDecode(decoder->queue);
//    if (symbol == 206) {
//      return;
//    } else {
//      printf("%s", decoder->queue);
//      decoder->i = 0;
//      write(decoder->ofd, &symbol, 1);
//    }

//    if (decoder->i == 4) { //
//      printf("%s", decoder->queue);
//      decoder->i = 0;
//      char symbol = morseDecode(decoder->queue);
//      write(decoder->ofd, &symbol, 1);
//    } else {
//
//      decoder->i = decoder->i + 1;
//      printf("Process morse: %d\n", decoder->i);
//    }

  } else if (signal == SIGALRM) { // end of morse string reached process 1...5 morse chars
      decoder->queue[decoder->i] = '\0';
      char symbol = morseDecode(decoder->queue);
      printf("%s", decoder->queue);
      decoder->i = 0;
      write(decoder->ofd, &symbol, 1);
  } else if (signal == SIGINT) {
    printf("Process received SIGINT\nClosing...\n");
    exit(1);
  }
}
