#include "shell.h"

int get_line(char *buff)
{
	size_t num;
	char *prompt = "($) ";

	/*buff = malloc(sizeof(char) * BUF_SIZE);*/
	if (buff == NULL)
		return (-1);
	if (isatty(STDIN_FILENO))
		TERMINAL(prompt);
	getline(&buff, &num, stdin);

	return (0);
}

int main(void)
{
	char *buff;
	char *argv[100] __attribute__((__unused__));
	int length, index;
	char *token;
	char *delimiter = " ";

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

		length = _strlen(buff);

		if (length == 0)
			break;

		/*if (buff[length - 1] == '\n')
			buff[length - 1] == '\0';*/

		if (_strcmp(buff, "exit") == 0)
			break;

		token = strtok(buff, delimiter);
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
