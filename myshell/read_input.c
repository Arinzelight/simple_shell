#include "main.h"

/**
 * read_input - reads line from the stdin
 *
 * Return: pointer which poins to a string with the content read
 * from line
 */

char *read_input(void)
{
	char *line_buffer = NULL;
	size_t buf_Size = 0;

	if (getline(&line_buffer, &buf_Size, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line_buffer);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line_buffer);
			perror("error occured while reading line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (line_buffer);

}
