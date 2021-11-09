#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

typedef struct line 
{
	char *input;
	char **args;
	char *command;
	char *envp;
	char *error;
	char *data;
} buff;

/* ----------Macros---------- */
#define TERMINAL(prompt) (write(STDIN_FILENO, prompt, _strlen(prompt)))
#define WRITE_OUT(ch) (write(STDIN_FILENO, ch, _strlen(ch)))
#define BUF_SIZE 256

/* ----------String Prototypes---------- */
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strdup(char *str);

/* ----------Handlers Prototypes---------- */
void sig_handler(int sig);
char *rmNewline(char *buff);
int get_line(char *buff);

/* ----------Environment Prototypes---------- */
int get_path_count(char *path);
char **get_path_array(char **env);
char *find_path(char **path_array, char *command);
void print_env(char **env);
int verify_path(char **arguments);

int execute(char *argv[]);
void parse(char *buff, char *argv[]);

#endif
