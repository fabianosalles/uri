#ifndef LOGGER_H
#define LOGGERH

#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void log_info(char *text);
void log_warn(char *text);
void log_error(char *text);
void log_success(char *text);

/* implementation */

void log_info(char *text){
    printf(ANSI_COLOR_RESET"%s", text);
}

void log_warn(char *text){
    printf(ANSI_COLOR_YELLOW"%s", text);
}

void log_error(char *text){
    printf(ANSI_COLOR_RED"%s", text);
}

void log_success(char *text){
    printf(ANSI_COLOR_RED"%s", text);
}

#endif