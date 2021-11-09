#include "shell.h"

/**
 * execute - Executes the commands given as input.
 *
 * @argv: The parsed input.
 *
 * Return: Always 0.
 */
int execute(char *argv[])
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (execve(argv[0], argv, NULL) == -1)
			perror("Error: ");
	}
	else
	{
		wait(&status);
	}
	return (0);
}

/**
 * parse - Parses the user input.
 *
 * @buff: String to be parsed.
 * @argv: Array to store the parsed string.
 */
void parse(char *buff, char *argv[])
{
	int index = 0;

	while (*buff != '\0')
	{
		while (*buff == ' ' || *buff == '\t' || *buff == '\n')
			*buff++ = '\0';
		argv[index] = buff;
		while (*buff != '\0' && *buff != ' ' && *buff != '\n' && *buff != '\t')
			buff++;
		index++;
	}
	argv[index] = NULL;
}
