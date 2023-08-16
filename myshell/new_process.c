#include "main.h"

/**
 * new_process - creates a new process (fork)
 * @args: array of strings that contains the command
 * and its argument (flags)
 *
 * Return: 1 if success, 0 otherwise
 */

int new_process(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("error in new_process\n");
		}
		exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		perror("error in new_process forking");
	}
	else
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
