#include "main.h"

/**
 * line_split - splits a string into multiple strings
 * @line_string: string to be split
 *
 * Return: pointer that points to the new array
 */

char **line_split(char *line_string)
{
	int buf_size = 64;
	int i = 0;
	char **tokens = malloc(buf_size * sizeof(char *));
	char *token;

	if (tokens == NULL)
	{
		_putstr("memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line_string, TOK_DELIM);
	while (token != NULL)
	{
		/*---handle comments----*/

		if (token[0] == '#')
			break;
		tokens[i] = token;
		i++;

		if (i >= buf_size)
		{
			buf_size += buf_size;
			tokens = realloc(tokens, buf_size * sizeof(char));
			if (tokens == NULL) 
			{
				_putstr("reallocation failed");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);

}
