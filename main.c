#include "shell.h"

int main(void)
{
	char *buff;
	size_t num;

	buff = malloc(sizeof(char) * BUF_SIZE);
	signal(SIGINT, sig_handler);
	while (1)
	{
		if (getline(&buff, &num, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				WRITE_OUT("\n");
			break;
		}
	}
	free(buff);
	return (0);
}
