#include "main.h"


int _putchar(char z)
{
	return (write (1, &z, 1));
}


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
