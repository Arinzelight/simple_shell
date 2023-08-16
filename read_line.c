#include "main.h"

/**
 * read_line - read a line from the stream
 *
 * Return: pointer that points the the read line
 */
char *read_line(void)
{
	int buf_size = 1024;
	int i = 0;
	char *line_buffer = malloc(sizeof(char) * buf_size);
	int line_char;

	if (line_buffer == NULL)
	{
		fprintf(stderr, "allocation error in read_stream");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line_char = getchar(); /* read first char from stream */
		if (line_char == EOF)
		{
			free(line_buffer);
			exit(EXIT_SUCCESS);
		}
		else if (line_char == '\n')
		{
			line_buffer[i] = '\0';
			return (line_buffer);
		}
		else
		{
			line_buffer[i] = line_char;
		}
		i++;
		if (i >= buf_size)
		{
			buf_size += buf_size;
			line_buffer = realloc(line_buffer, buf_size);
			if (line_buffer == NULL)
			{
				fprintf(stderr, "reallocation error in read_stream");
				exit(EXIT_FAILURE);
			}
		}
	}
}
