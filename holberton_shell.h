#ifndef _HOLBERTON_SHELL_H
#define _HOLBERTON_SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <string.h>


char *_strdup(char *str);
int _putchar(char c);
int print_number(size_t a);
char *_getenv(const char *name, char **env);
void getline_fail(char **argv, char *line);
void sighelp(int a);
void prompt(int a);
char *_strtok(char *str, const char *delim);
char **tok(char *st, char *dil);
void free_shell(char **argv, char *line);
int stat_exec(char **argv, char *line, size_t i, char **env);
char **_path(int argc, char **argv, char **env);
char *_strcpy(char *dest, char *src);
int _strcmp(const char *s1, char *s2);
int builtin(char **env, char **argv, char *line, int extstat);
int _strlen(char *);

#endif /*HOLBERTON_SHELL_H*/
