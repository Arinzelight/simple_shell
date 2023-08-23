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
		status = exec_builtin(args);

		/*========== free memory========*/

		free(buffer);
		free(args);
		/*========== exit with status ========*/

		if (status >= 0)
		{
			exit(status);
		}



	} while (status == -1);
}
