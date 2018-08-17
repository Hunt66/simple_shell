#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	pid_t parent;

	parent = open("/proc/sys/kernel/pid_max", O_RDONLY);
	printf("%u\n", parent);
	return (0);
}
