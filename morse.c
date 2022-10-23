//
// Created by Otso Luukkanen on 19.10.2022.
//
// CPP program to demonstrate Morse code


#include "morse.h"

// function to encode a alphabet as
// Morse code
char* morseEncode(char x)
{
    char* s = malloc(2);
    // refer to the Morse table
    // image attached in the article
    switch (x) {
            case 'a':
                return ".-";
            case 'b':
                return "-...";
            case 'c':
                return "-.-.";
            case 'd':
                return "-..";
            case 'e':
                return ".";
            case 'f':
                return "..-.";
            case 'g':
                return "--.";
            case 'h':
                return "....";
            case 'i':
                return "..";
            case 'j':
                return ".---";
            case 'k':
                return "-.-";
            case 'l':
                return ".-..";
            case 'm':
                return "--";
            case 'n':
                return "-.";
            case 'o':
                return "---";
            case 'p':
                return ".--.";
            case 'q':
                return "--.-";
            case 'r':
                return ".-.";
            case 's':
                return "...";
            case 't':
                return "-";
            case 'u':
                return "..-";
            case 'v':
                return "...-";
            case 'w':
                return ".--";
            case 'x':
                return "-..-";
            case 'y':
                return "-.--";
            case 'z':
                return "--..";
            case '1':
                return ".----";
            case '2':
                return "..---";
            case '3':
                return "...--";
            case '4':
                return "....-";
            case '5':
                return ".....";
            case '6':
                return "-....";
            case '7':
                return "--...";
            case '8':
                return "---..";
            case '9':
                return "----.";
            case '0':
                return "-----";
            default:
                 /* gives {\0, \0} */
                s[0] = x;
                s[1] = '\0';
                return s;
                //return "Found invalid character: ";
                //exit(0);
        }
}


char morseDecode (char *s)
{
    if (strcmp(s, ".-") == 0)
        {
            return 'a';
        }
    else if (strcmp(s, "-...") == 0)
        {
            return 'b';
        } else if (strcmp(s, "-.-.") == 0)
        {
            return 'c';
        } else if (strcmp(s, "-..") == 0)
        {
            return 'd';
        } else if (strcmp(s, ".") == 0)
        {
            return 'e';
        } else if (strcmp(s, "..-.") == 0)
        {
            return 'f';
        } else if (strcmp(s, "--.") == 0)
        {
            return 'g';
        } else if (strcmp(s, "....") == 0)
        {
            return 'h';
        } else if (strcmp(s, "..") == 0)
        {
            return 'i';
        } else if (strcmp(s, ".---") == 0)
        {
            return 'j';
        } else if (strcmp(s, "-.-") == 0)
        {
            return 'k';
        } else if (strcmp(s, ".-..") == 0)
        {
            return 'l';
        } else if (strcmp(s, "--") == 0)
        {
            return 'm';
        } else if (strcmp(s, "-.") == 0)
        {
            return 'n';
        } else if (strcmp(s, "---") == 0)
        {
            return 'o';
        } else if (strcmp(s, ".--.") == 0)
        {
            return 'p';
        } else if (strcmp(s, "--.-") == 0)
        {
            return 'q';
        } else if (strcmp(s, ".-.") == 0)
        {
            return 'r';
        } else if (strcmp(s, "...") == 0)
        {
            return 's';
        } else if (strcmp(s, "-") == 0)
        {
            return 't';
        } else if (strcmp(s, "..-") == 0)
        {
            return 'u';
        } else if (strcmp(s, "...-") == 0)
        {
            return 'v';
        } else if (strcmp(s, ".--") == 0)
        {
            return 'w';
        } else if (strcmp(s, "-..-") == 0)
        {
            return 'x';
        } else if (strcmp(s, "-.--") == 0)
        {
            return 'y';
        } else if (strcmp(s, "--..") == 0)
        {
            return 'z';
        } else if (strcmp(s, "-.--") == 0)
        {
            return 'y';
        } else if (strcmp(s, ".----") == 0)
        {
            return '1';
        } else if (strcmp(s, "..---") == 0)
        {
            return '2';
        } else if (strcmp(s, "...--") == 0)
        {
            return '3';
        } else if (strcmp(s, "....-") == 0)
        {
            return '4';
        } else if (strcmp(s, ".....") == 0)
        {
            return '5';
        } else if (strcmp(s, "-....") == 0)
        {
            return '6';
        } else if (strcmp(s, "--...") == 0)
        {
            return '7';
        } else if (strcmp(s, "---..") == 0)
        {
            return '8';
        } else if (strcmp(s, "----.") == 0)
        {
            return '9';
        } else if (strcmp(s, "-----") == 0)
        {
            return '0';
        }

/* more else if clauses */
    else /* default: */
        { return '$';
        }

}
//    //char* s = malloc(2);
//    // refer to the Morse table
//    // image attached in the article
//    switch(s) {
//            case ".-":
//                return 'a';
//            case 'b':
//                return "-...";
//            case 'c':
//                return "-.-.";
//            case 'd':
//                return "-..";
//            case 'e':
//                return ".";
//            case 'f':
//                return "..-.";
//            case 'g':
//                return "--.";
//            case 'h':
//                return "....";
//            case 'i':
//                return "..";
//            case 'j':
//                return ".---";
//            case 'k':
//                return "-.-";
//            case 'l':
//                return ".-..";
//            case 'm':
//                return "--";
//            case 'n':
//                return "-.";
//            case 'o':
//                return "---";
//            case 'p':
//                return ".--.";
//            case 'q':
//                return "--.-";
//            case 'r':
//                return ".-.";
//            case 's':
//                return "...";
//            case 't':
//                return "-";
//            case 'u':
//                return "..-";
//            case 'v':
//                return "...-";
//            case 'w':
//                return ".--";
//            case 'x':
//                return "-..-";
//            case 'y':
//                return "-.--";
//            case 'z':
//                return "--..";
//            case '1':
//                return ".----";
//            case '2':
//                return "..---";
//            case '3':
//                return "...--";
//            case '4':
//                return "....-";
//            case '5':
//                return ".....";
//            case '6':
//                return "-....";
//            case '7':
//                return "--...";
//            case '8':
//                return "---..";
//            case '9':
//                return "----.";
//            case '0':
//                return "-----";
//            default:
//                /* gives {\0, \0} */
//                s[0] = x;
//            s[1] = '\0';
//            return s;
//            //return "Found invalid character: ";
//            //exit(0);
//        }
//}

void morseCode(char* s, pid_t parentPid) {
    // character by character print
    // Morse code
    char morseChar[8];
    for (int i = 0; s[i]; i++) {
        printf("%s",morseEncode(s[i]));
        snprintf (morseChar, 8,"%s", morseEncode (s[i]));
        for (int j = 0; morseChar[j]; j++) {
            printf("morse char: %c", s[j]);
            if (morseChar[j] == '.') {
                kill(parentPid, SIGUSR1);
            } else if (morseChar[j] == '-') {
                kill(parentPid, SIGUSR2);
            } else continue;
        }
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
            write(ofd, buf, n);
    }
}
