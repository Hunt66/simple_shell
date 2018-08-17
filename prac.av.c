#include <stdio.h>

int main(int ac, char**av)
{
	int c;

	for (c = 1; av[c] != NULL; c++)
		printf("%s ", av[c]);
}
