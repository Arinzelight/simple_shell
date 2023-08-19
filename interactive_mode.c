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
		_putstr("$ ");

		line_string = read_input();
		args = line_split(line_string);
		status = exec_args(args);

	
		free(line_string);
		free(args);


		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
