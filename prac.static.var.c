#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void _stat(st)
{
	char *str = malloc(15);
	char *sstr = "The number is 9";
	strcpy(str, st);
	if (str == sstr)
		return;
	printf("%s\n", str);
	str[14] = str[14] + 1;
	_stat();
}

int main()
{
	static char *str = "The number is 0";
	printf("stat\n");
	_stat(str);
	printf("done\n");
	return (0);
}
