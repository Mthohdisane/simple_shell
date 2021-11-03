#include "shell.h"

/**
 * _strlen - Get length of string excluding '\0'.
 *
 * @str: The string whose length is to be found.
 *
 * Return: The length of @str.
 */

int _strlen(char *str)
{
	int len;

	for (len = 0; *(str + len) != '\0'; len++);
	return (len);
}
