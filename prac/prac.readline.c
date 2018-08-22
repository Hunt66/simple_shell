#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *buf;
	size_t characters, size = 1;

	buf = malloc(sizeof(char) * size);

	if (!buf)
		return (-1);

	printf("$");
	characters = getline(&buf, &size, stdin);
	printf("%s", buf);
}
