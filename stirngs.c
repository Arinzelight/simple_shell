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
 * Return: Number of strings printed
 */

int _putstr(char *str)
{
	int count = 0, i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		count += 1;
		i++;
	}
	return (count);
}
