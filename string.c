#include "main.h"

/**
 * str_len - Calculates the length of a string
 * @str: Str to check its length
 * Return: Lentgh of dtring
 */

int str_len(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * str_dup - Function that duplicates string
 * @s: Str to duplicate
 * Return: Duplicated string
 */

char *str_dup(char *s)
{
	char *cpy_s;
	int len = 0, x;

	if (s == NULL)
		return (NULL);

	len = str_len(s) + 1;

	cpy_s = malloc(sizeof(*cpy_s) * len);

	if (cpy_s == NULL)
	{
		return (NULL);
	}

	for (x = 0; x < len; x++)
		cpy_s[x] = s[x];

	return (cpy_s);
}

/**
 * str_cat - Function that concatenates two string
 * @dest: Destination of string
 * @src: String source
 * Return: Concatenated string
 */
char *str_cat(char *dest, char *src)
{
	int x = 0;
	int y = 0;

	while (dest[x] != '\0')
	{
		x++;
	}
	while (src[y] != '\0')
	{
		dest[x + y] = src[y];
		y++;
	}
	dest[x + y] = '\0';
	return (dest);
}

/**
 * str_cpy - Function to copy string
 * @dest: Destination to copy to
 * @src: String to copy
 * Return: Copied string
 */
char *str_cpy(char *dest, char *src)
{
	int x = 0;

	while (src[x] != '\0')
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}
