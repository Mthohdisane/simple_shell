#include "shell.h"

/**
 * main - Program's entry point.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *buff;
	int index;
	char *token;
	char *delimiter = " ";
	char *str;
	char *argv[256] __attribute__((unused));

	buff = malloc(sizeof(char) * BUF_SIZE);
	signal(SIGINT, sig_handler);
	while (1)
	{
		if (get_line(buff) == -1)
		{
			if (isatty(STDIN_FILENO))
				WRITE_OUT("\n");
			break;
		}
		str = rmNewline(buff);

		token = strtok(str, delimiter);
		index = 0;
		while (token != NULL)
		{
			argv[index] = token;
			token = strtok(NULL, delimiter);
			index++;
		}
		argv[index] = NULL;
	}
	free(buff);
	return (0);
}
