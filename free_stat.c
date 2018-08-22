#include"holerton_shell.h"

/**
 *free_stat - frees all things in a struct stat
 *@st: the stat struct to be freed
 *Return: void
 */


void free_stat(struct stat st);
{
	free(st->st_dev);
	free(st->st_ino);
	free(st->st_mode);
	free(st->st_nlink);
	free(st->st_uid);
	free(st->st_gid);
	free(st->st_rdev);
	free(st->st_size);
	free(st->st_atime);
	free(st->st_mtime);
