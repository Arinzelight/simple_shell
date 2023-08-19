#include "main.h"

/**
 * interactive_mode - shell in interactive mode
 *
 * Return: void
 */

void interactive_mode(void)
{
	char *line_string;
	char **args;
	int status = -1;


	do {
		printf("$ ");

		line_string = read_input();
		args = line_split(line_string);

		/* Check if the user entered the 'exit' command*/
		if (args[0] != NULL && strcmp(args[0], "exit") == 0)
		{
			free(line_string);
			free(args);
			exit(0);
		}
		status = exec_args(args);
		/*--------- free memory-------*/
		free(line_string);
		free(args);

		/*--------exit with status---------*/
	} while (status == -1);
}
