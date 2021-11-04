#include "shell.h"

/**
 * sig_handler - Handles the signal during process interruption.
 *
 * @sig: Signal identifier.
 */
void sig_handler(int sig)
{
	char *prompt = "($) ";

	(void)sig;
	WRITE_OUT("\n");
	TERMINAL(prompt);
}

/**
 * rmNewline - Removes the '\n' placed by getline function.
 *
 * @buff: String stored by getline.
 *
 * Return: The string without '\n'
 */
char *rmNewline(char *buff)
{
	int index;
	char *str;

	str = malloc(sizeof(char) * BUF_SIZE);
	if (str == NULL)
		return (NULL);

	for (index = 0; *(buff + index) != '\n'; index++)
		*(str + index) = *(buff + index);

	free(str);
	return (str);
}

/**
 * get_line - Prints out the prompt and reads from the buffer.
 *	      The input is stored into @buff.
 *
 * @buff: User input.
 *
 * Return: 0 on success, -1 on failure.
 */
int get_line(char *buff)
{
	size_t num = BUF_SIZE;
	char *prompt = "($) ";

	if (buff == NULL)
		return (-1);
	if (isatty(STDIN_FILENO))
		TERMINAL(prompt);

	getline(&buff, &num, stdin);

	return (0);
}
