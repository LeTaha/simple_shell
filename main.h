#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>

#define MAX_COM_LEN 100

char *fgetstm(char *str, int size, FILE *stream);
int printftm(const char *format, ...);
int fprintftm(FILE *stream, const char *format, ...);
int execlptm(const char *file, const char *arg, ...);

#endif
