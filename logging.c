//
// Created by Otso Luukkanen on 23.10.2022.
//

#include "logging.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logger(const char* tag, const char* message) {
  time_t now;
  time(&now);
  printf("[%s] [%s]: %s\n", ctime(&now), tag, message);
}