#include "main.h"

/**
 * line_split - function to tokenize input string
 * @line_string: string to be tokenize
 *
 * Return: pointer to the first token
 */

char **line_split(char *line_string)
{
	int buf_size = 64;
	int count = 0;
	char **tokens;
	char *token;

	tokens = malloc(buf_size * sizeof(char *));

	if (tokens == NULL)
	{
		perror("memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line_string, TOK_DELIM);
	while (token != NULL)
	{

		if (token[0] == '#')
			break;
		tokens[count] = token;
		count++;

		if (count >= buf_size)
		{
			buf_size += buf_size;
			tokens = realloc(tokens, buf_size * sizeof(char));
			if (tokens == NULL)
			{
				perror("reallocation failed");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[count] = NULL;
	return (tokens);

}
