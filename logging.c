//
// Created by Otso Luukkanen on 23.10.2022.
//

#include "logging.h"
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

char time_str[64]; // string for storing formatted time string
int len; // len for snprintf
// log string for writing to pipe
char log_str[128];

// time for logging
time_t rawtime;
struct tm * timeinfo;

void logger(int log_pipe, const char* format_message) {

}
