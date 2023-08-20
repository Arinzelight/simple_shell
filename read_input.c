#include "main.h"

/**
 * read_input - function to reads line from input stream
 *
 * Return: pointer to the read input
 */

char *read_input(void)
{
	char *line_buffer = NULL;
	size_t buf_Size = 0;
	ssize_t chars_read;

	chars_read = getline(&line_buffer, &buf_Size, stdin);

	if (chars_read == -1)
	{
		free(line_buffer);
		exit(EXIT_FAILURE);
	}


	/**
	 * if (getline(&line_buffer, &buf_Size, stdin) == -1)
	{

		if (feof(stdin))
		{
			free(line_buffer);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line_buffer);
			perror("");
			exit(EXIT_FAILURE);
		}
	}
	*/

	return (line_buffer);
}
