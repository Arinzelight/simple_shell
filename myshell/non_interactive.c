#include "main.h"

/**
 * non_interactive_mode - command line interpreter
 *
 * Return: void
 */

void non_interactive_mode(void)
{
	char *line_string;
	char **args;
	int status = -1;

	do {
		line_string = read_line();
		args = line_split(line_string);
		status = exec_args(args);
		/* avoid memory leaks */
		free(line_string);
		free(args);
		/* exit with status */
		if (status >= 0)
		{
		exit(status);
		}
	} while (status == -1);
}
