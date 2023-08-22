#include "main.h"

/**
 * interactive_mode - shell in interactive mode
 *
 * Return: void
 */

void interactive_mode(void)
{
	char *buffer;
	char **args;
	int status = -1;


	do {
		write(STDOUT_FILENO, PROMPT, 2);

		buffer = read_input();
		args = tokenize(buffer);


		/* Check if the user entered the 'exit' command*/
		if (args[0] != NULL && strcmp(args[0], "exit") == 0)
		{
			free(buffer);
			free(args);
			exit(0);
		}
		exec_builtin(args);


		free(buffer);
		free(args);




	} while (status == -1);
}
