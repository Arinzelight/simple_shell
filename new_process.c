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
	int exe;
	char *cmd, *av;
	int status;

	if (args != NULL)
	{
		cmd = args[0];
		av = find_path(cmd);

		if (av == NULL)
		{
			printf("path not found");
		}

		child_pid = fork();
		if (child_pid == 0)
		{
			exe = execve(av, args, environ);
			if (exe == -1)
			{
				perror("execve failed\n");
			}
			exit(EXIT_FAILURE);
		}
		else if (child_pid < 0)
		{
			perror("fork failed");
		}
		else
		{
			do {
				waitpid(child_pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		if (av != cmd)
			free(av);
		return (-1);
	}
	return (0);
}
