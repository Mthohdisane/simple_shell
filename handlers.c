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
