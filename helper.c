#include "monty.h"

/**
  * str_int - checks if all characters in string are integer
  * @str: string to check
  * Return: 1 if not all integers, 0 if all integers
  */
int str_int(char *str)
{
	if (str == NULL)
		return (1);

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}
