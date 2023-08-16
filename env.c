#include "main.h"

/**
 * env - function that prints enviroment variables
 * @args: arguments
 *
 * Return: 1 on success, 0 otherwise
 */
int env(char **args)
{
	int n = 0;
	(void)(**args);

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], str_len(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		n++;
	}
	return (-1);
}
