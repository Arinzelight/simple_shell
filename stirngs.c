#include "main.h"

/**
 * _putchar - Function that prints character
 * @z: character to print
 * Return: character printed
 */

int _putchar(char z)
{
	return (write(1, &z, 1));
}

/**
 * _putstr - Function to print string
 * @str: string to print
 * @fd: file descriptor
 * Return: Number of strings printed
 */

int _putstr(char *str, int fd)
{
	int count = 0, i = 0;

	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		count += 1;
		i++;
	}
	return (count);
}

/**
 * str_cmp - Function that Compare two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0
 */

int str_cmp(char *s1, char *s2)
{
	int x = 0;

	while (s1[x] != '\0' && s2[x] != '\0')
	{
		if (s1[x] != s2[x])
		{
			return (s1[x] - s2[x]);
		}
		x++;
	}
	return (0);
}
