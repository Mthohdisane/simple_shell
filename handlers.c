#include "shell.h"

/**
 * sig_handler - Handles the signal during process interruption.
 *
 * @sig: Signal identifier.
 */
void sig_handler(int sig)
{
	char *prompt = "($) ";

	if (sig == SIGINT)
	{
		WRITE_OUT("\n");
		TERMINAL(prompt);
	}
}
