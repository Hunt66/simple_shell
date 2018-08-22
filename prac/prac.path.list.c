#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

/**
 *linked list struct of strings
 */


typedef struct liststr_s
{
	char *str;
	struct liststr_s *next;
} liststr_t;


/**
 *prints the path one directory per line
 */

int main()
{
	char cwd[PATH_MAX];
	int i, j = 0, k = 0, l = 0;
	liststr_t *head, *new;
	char **str = NULL;

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		for (i = 0 ; cwd[i] != '\0' ; i++)
		{
			if (cwd[i] == '/')
				j++;
		}
		str = malloc(sizeof(char*) * j);

		head = malloc(sizeof(liststr_t));
		if (!head)
			return (-1);
		new = malloc(sizeof(liststr_t));
		if (!new)
			return (-1);


		new = head;


		str[0] = malloc(sizeof(5000));
		for (i = 1 ; cwd[i - 1] != '\0' ; i++)
		{

			if (cwd[i] == '/' || cwd[i] == '\0')
			{
				str[l][k] = '\0';
				l = l + 1;
				str[l] = malloc(k + 5);
				k = 0;

			}
			else
			{

				str[l][k] = cwd[i];

				k++;
			}
	    	}
		str[l] = NULL;
		k = 0;

		new->str = str[0];

		for (j = 1 ; str[j] != NULL ; j++)
		{
			new->next = malloc(sizeof(liststr_t));
			new = new->next;
			new->str = str[j];

		}
		new->next = malloc(sizeof(liststr_t));
		new->next = NULL;



		new = head;
    		for (i = 0 ; head != NULL ; i++)
		{

			printf("%s\n", head->str);
			head = head->next;
	       	}



	}
	else
	{
		perror("error\n");
		return (1);
	}
	return (0);
}
