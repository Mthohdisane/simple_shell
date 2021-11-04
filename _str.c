#include "shell.h"

/**
 * _strcpy - Copies a string from @src to @dest.
 *
 * @src: String source
 * @dest: String destination
 *
 * Return: The copied string in @dest.
 */
char *_strcpy(char *dest, char *src)
{
	int index;

	for (index = 0; src[index] != '\0'; index++)
	{
		dest[index] = src[index];
	}
	dest[index] = '\0';
	return (dest);
}

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

	for (len = 0; *(str + len) != '\0'; len++)
		;
	return (len);
}

/**
 * _strcmp - Compare two strings
 *
 * @str1: First string.
 * @str2: Second string.
 *
 * Return: 1 if either strings is NULL.
 *	   The differemce between @str1 & @str2
 */
int _strcmp(char *str1, char *str2)
{
	int idx = 0, index;

	if (str1 == NULL || str2 == NULL)
		return (1);
	for (index = 0; str1[index]; index++)
	{
		if (str1[index] != str2[index])
		{
			idx = str1[index] - str2[index];
			break;
		}
		else
			continue;
	}
	return (idx);
}

/**
 * _strdup - Duplicates @str.
 *
 * @str: A string to be duplicated.
 *
 * Return: A duplicate string.
 *	   On failure, NULL.
 */
char *_strdup(char *str)
{
	char *dub;

	if (str == NULL)
		return (NULL);
	dub = malloc(_strlen(str) + 1);
	if (dub == NULL)
		return (NULL);
	_strcpy(dub, str);
	return (dub);
}
