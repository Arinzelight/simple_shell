#include "main.h"

/**
 * exec_args - map if command is a builtin or a process
 * @args: command and its arguments (flags)
 *
 * Return: 1 on success, otherwise 0
 */

int exec_args(char **args)
{
	char *builtin_funcs[] = {"env", "cd", "exit",};

	int (*builtin_func[])(char **) = {&env, &my_cd, &my_exit, NULL};

	size_t i = 0;


	if (args[0] == NULL)
	{
		/*---handle empty command---*/
		return (-1);
	}
	/*-----if command is builtin-------*/

	for (; i < sizeof(builtin_funcs) / sizeof(char *); i++)
	{
		/*if the command matches execute the builtin command*/
		if (str_cmp(args[0], builtin_funcs[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	/* create a new process */
	return (new_process(args));
}
