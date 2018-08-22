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


/**
 * struct format - Struct format
 * @b: the letter
 * @func: function associated with letter
 */
typedef struct format
{
	char b;
	int (*func)(va_list);
} fm_t;

int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(char *);
int int_pow(int x, int y);

int _printfc(va_list);
int _printfb(va_list);
int _printfs(va_list);
int _printfp(va_list);
int _printfd(va_list);
int _printfr(va_list);    /*printf prototypes*/
int _printfR(va_list);
int _printfu(va_list);
int _printfo(va_list);
int _printfx(va_list);
int _printfX(va_list);
int _printfS(va_list);
int _printfpp(va_list);

char *_strtok(char *str, const char *delim);
char **tok(char *st, char *dil);              /*prototypes*/
void free_shell(char **argv, char *line);
int stat_exec(char **argv, char *line);
char **_path(int argc, char **argv, char **env);

#endif /*HOLBERTON_SHELL_H*/
