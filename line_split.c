#include "main.h"

/**
 * tokenize - function to tokenize input string
 * @buff: string to be tokenize
 *
 * Return: pointer to the first token
 */

char **tokenize(char *buff)
{
	int size_of_buffer = 64;
	int count = 0;
	char **tokens;
	char *token;

	tokens = malloc(size_of_buffer * sizeof(char *));

	if (tokens == NULL)
	{
		perror("memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(buff, DELIMETER);
	while (token != NULL)
	{

		if (token[0] == '#')
			break;
		tokens[count] = token;
		count++;

		if (count >= size_of_buffer)
		{
			size_of_buffer += size_of_buffer;
			tokens = realloc(tokens, size_of_buffer * sizeof(char));
			if (tokens == NULL)
			{
				perror("reallocation failed");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIMETER);
	}
	tokens[count] = NULL;
	return (tokens);

}
