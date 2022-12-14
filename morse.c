//
// Created by Otso Luukkanen on 19.10.2022.
//
// C program to demonstrate Morse code


#include <stdlib.h>
#include <time.h>
#include "morse.h"

// function to encode a alphabet as
// Morse code
char *morseEncode(char x) {
  // switch case table to translate char to morse string
  switch (x) {
    case 'A':return ".-";
    case 'B':return "-...";
    case 'C':return "-.-.";
    case 'D':return "-..";
    case 'E':return ".";
    case 'F':return "..-.";
    case 'G':return "--.";
    case 'H':return "....";
    case 'I':return "..";
    case 'J':return ".---";
    case 'K':return "-.-";
    case 'L':return ".-..";
    case 'M':return "--";
    case 'N':return "-.";
    case 'O':return "---";
    case 'P':return ".--.";
    case 'Q':return "--.-";
    case 'R':return ".-.";
    case 'S':return "...";
    case 'T':return "-";
    case 'U':return "..-";
    case 'V':return "...-";
    case 'W':return ".--";
    case 'X':return "-..-";
    case 'Y':return "-.--";
    case 'Z':return "--..";
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
    case '&':return ".-...";
    case '\'':return ".----.";
    case '@':return ".--.-";
    case ')':return "-.--.-";
    case '(':return "-.--.";
    case ':':return "---...";
    case ',':return "--..--";
    case '=':return "-...-";
    case '!':return "-.-.--";
    case '.':return ".-.-.-";
    case '-':return "-.....-";
    case '+':return ".-.-.";
    case '"':return ".-..-.";
    case '?':return "..--..";
    case '/':return "-..-.";

    default:
      // if there is an unrecognized character
      // this will be sent and replaced with star / multiplication sign '*'
      // these include newline and space
      return ".......";

  }
}

char morseDecode(char *s) {
  // morse string to char
  if (strcmp(s, ".-") == 0) {
    return 'A';
  } else if (strcmp(s, "-...") == 0) {
    return 'B';
  } else if (strcmp(s, "-.-.") == 0) {
    return 'C';
  } else if (strcmp(s, "-..") == 0) {
    return 'D';
  } else if (strcmp(s, ".") == 0) {
    return 'E';
  } else if (strcmp(s, "..-.") == 0) {
    return 'F';
  } else if (strcmp(s, "--.") == 0) {
    return 'G';
  } else if (strcmp(s, "....") == 0) {
    return 'H';
  } else if (strcmp(s, "..") == 0) {
    return 'I';
  } else if (strcmp(s, ".---") == 0) {
    return 'J';
  } else if (strcmp(s, "-.-") == 0) {
    return 'K';
  } else if (strcmp(s, ".-..") == 0) {
    return 'L';
  } else if (strcmp(s, "--") == 0) {
    return 'M';
  } else if (strcmp(s, "-.") == 0) {
    return 'N';
  } else if (strcmp(s, "---") == 0) {
    return 'O';
  } else if (strcmp(s, ".--.") == 0) {
    return 'P';
  } else if (strcmp(s, "--.-") == 0) {
    return 'Q';
  } else if (strcmp(s, ".-.") == 0) {
    return 'R';
  } else if (strcmp(s, "...") == 0) {
    return 'S';
  } else if (strcmp(s, "-") == 0) {
    return 'T';
  } else if (strcmp(s, "..-") == 0) {
    return 'U';
  } else if (strcmp(s, "...-") == 0) {
    return 'V';
  } else if (strcmp(s, ".--") == 0) {
    return 'W';
  } else if (strcmp(s, "-..-") == 0) {
    return 'X';
  } else if (strcmp(s, "-.--") == 0) {
    return 'Y';
  } else if (strcmp(s, "--..") == 0) {
    return 'Z';
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
  } else if (strcmp(s, ".-...") == 0) {
    return '&';
  } else if (strcmp(s, ".----.") == 0) {
    return '\'';
  } else if (strcmp(s, ".--.-") == 0) {
    return '@';
  } else if (strcmp(s, "-.--.-") == 0) {
    return ')';
  } else if (strcmp(s, "-.--.") == 0) {
    return '(';
  } else if (strcmp(s, "---...") == 0) {
    return ':';
  } else if (strcmp(s, "--..--") == 0) {
    return ',';
  } else if (strcmp(s, "-...-") == 0) {
    return '=';
  } else if (strcmp(s, "-.-.--") == 0) {
    return '!';
  } else if (strcmp(s, ".-.-.-") == 0) {
    return '.';
  } else if (strcmp(s, "-.....-") == 0) {
    return '-';
  } else if (strcmp(s, ".-.-.") == 0) {
    return '+';
  } else if (strcmp(s, ".-..-.") == 0) {
    return '"';
  } else if (strcmp(s, "..--..") == 0) {
    return '?';
  } else if (strcmp(s, "-..-.") == 0) {
    return '/';
  }

  else /* default: */
  {
    return '*'; // random ASCII char '*' to signify unrecognized character
  }

}

void morseCode(char *s, pid_t parentPid) {
  // character by character print
  // Morse code
  char morseChar[10];
  for (int i = 0; s[i]; i++) {

    sigset_t sigset;
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGUSR1);
    sigprocmask(SIG_BLOCK, &sigset, NULL);

    int sig;

    snprintf(morseChar, 8, "%s", morseEncode(s[i]));
    for (int j = 0; morseChar[j]; j++) {
      // wait for response from parent process
      // allows synchronization
      sigwait(&sigset, &sig);
      if (morseChar[j] == '.') {
        kill(parentPid, SIGUSR1);
      } else if (morseChar[j] == '-') {
        kill(parentPid, SIGUSR2);
      } else continue;
    }
    sigwait(&sigset, &sig);
    kill(parentPid, SIGALRM); // end of one text char
  }

}

void readSendMorse(int ifd, pid_t parentPid) {
  char buf[129];
  long n;
  // read from input file until EOF is reached connection closes
  while ((n = read(ifd, buf, 128)) > 0) {
      buf[n] = '\0';  // re-terminate
    morseCode(buf, parentPid);
    }

  sleep(1);

}
// initialize decoder struct that stores morse charachers '-' and '.'
struct Decoder initDecoder(int ofd) {
  struct Decoder ret = {.i = 0, .ofd = ofd};
  ret.queue[9] = '\0';
  return ret;
}

// process one morse character / signal at a time
void processMorse(struct Decoder *decoder, char signal) {
  if (signal == SIGUSR1 || signal == SIGUSR2/* || signal == SIGALRM*/) {
    if (signal == SIGUSR1) {
      decoder->queue[decoder->i] = '.';
    } else {
      decoder->queue[decoder->i] = '-';
    }
    decoder->queue[decoder->i + 1] = '\0'; // close string
    decoder->i = decoder->i + 1; // next index

  } else if (signal == SIGALRM) { // end of morse string reached process 1...5 morse chars
    decoder->queue[decoder->i] = '\0';
    char symbol = morseDecode(decoder->queue);
    decoder->i = 0;
    write(decoder->ofd, &symbol, 1);
  } else if (signal == SIGINT) {
    //printf("Process received SIGINT\nClosing...\n");
    exit(1);
  }
}
