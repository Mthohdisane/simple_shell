#include "shell.h"

/**
 * main - Program's entry point.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *buff;
	int status;
	char *str;
	char *argv[BUF_SIZE];

	buff = malloc(sizeof(char) * BUF_SIZE);
	while (1)
	{
		if (get_line(buff) == -1)
		{
			if (isatty(STDIN_FILENO))
				WRITE_OUT("\n");
			break;
		}
		str = rmNewline(buff);
		parse(str, argv);
		if (_strcmp(argv[0], "exit") == 0)
			break;
		execute(argv);
	}
	free(buff);
	return (0);
}
