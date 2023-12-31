#include "main.h"
/**
 * find_path - function to the PATH variable
 * @arg: command to locate
 * Return: the path
 */
char *find_path(char *arg)
{
	char *delimeter = ":", *path, *cpy_path;
	char *pathTok, *fileName;
	struct stat args_line;

	path = getenv("PATH");
	if (path != NULL)
	{
		cpy_path = str_dup(path);
		pathTok = strtok(cpy_path, delimeter);
		while (pathTok)
		{
			fileName = malloc(str_len(arg) + str_len(pathTok) + 2);
			str_cpy(fileName, pathTok);
			str_cat(fileName, "/");
			str_cat(fileName, arg);
			str_cat(fileName, "\0");

			/*check if path exist*/
			if (stat(fileName, &args_line) == 0)
			{
				free(cpy_path);
				return (fileName);
			}
			else
			{
				free(fileName);
				pathTok = strtok(NULL, delimeter);
			}
		}
		free(cpy_path);

		/*check if the arg exist*/
		if (stat(arg, &args_line) == 0)
		{
			return (arg);
		}
		return (NULL);
	}
	return (NULL);
}
