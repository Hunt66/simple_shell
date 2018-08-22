#ifndef _HOLBERTON_SHELL_H
#define _HOLBERTON_SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>    /*included header files*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

char *_strtok(char *str, const char *delim);
char **tok(char *st, char *dil);              /*prototypes*/
void free_shell(char **argv, char *line);
int stat_exec(char **argv, char *line);


#endif /*HOLBERTON_SHELL_H*/
