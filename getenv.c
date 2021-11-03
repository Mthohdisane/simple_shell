#include "shell.h"

/**
 * get_path_count - counts number of directories in PATH
 * @path: PATH string
 *
 * Return: number of directories
 */

int get_path_count(char *path)
{
	int i, count;

	i = 0;
	count = 0;
	while (path[i] != '\0')
	{
		if (path[i] == '=' || path[i] == ':')
			count++;
		i++;
	}

	return (count);
}

/**
 * get_path_array - creates an array of PATH directories
 * @env: user environment
 *
 * Return: array of strings
 */

char **get_path_array(char **env)
{
	unsigned int i, j, path_count;
	int compare = 0;
	char *token, *token2,  *mypath;
	char **path_array;

	i = 0;
	j = 0;
	while (env[i] != NULL)
	{
		compare = _strcmp(env[i], "PATH");
		if (compare == 0)
		{
			mypath = _strdup(env[i]);
			path_count = get_path_count(mypath);
			token = strtok(mypath, "=");
			token = strtok(NULL, "=");
			path_array = malloc(sizeof(char *) * (path_count + 1));
			if (path_array == NULL)
				return (NULL);
			if (token[0] == ':')
			{
				path_array[j] = _strdup("./");
				j++;
				token2 = strtok(token, ":");
				token2 = strtok(NULL, ":");
			}
			else
				token2 = strtok(token, ":");
			while (j < path_count)
			{
				path_array[j] = _strdup(token2);
				j++;
				token2 = strtok(NULL, ":");
			}
		}
		i++;
	}
	path_array[path_count] = NULL;
	free(mypath);
	return (path_array);
}

/**
 * find_path - find the PATH of a command
 * @path_array: array of directories in PATH
 * @command: command to find path for
 *
 * Return: path of command, NULL if it fails
 */

char *find_path(char **path_array, char *command)
{
	int i, j, ok_f = 0, ok_x = 0, dir_len, com_len, total_len;
	char *path;

	for (i = 0; path_array[i] != NULL; i++)
	{
		dir_len = _strlen(path_array[i]);
		com_len = _strlen(command);
		total_len = dir_len + com_len;
		path = malloc(sizeof(char) * (total_len + 2));
		if (path == NULL)
		{
			free_array(path_array);
			return (NULL);
		}
		j = 0;
		while (j < dir_len)
		{
			path[j] = path_array[i][j];
			j++;
		}
		path[j] = '/';
		j = 0;
		while (j < com_len)
		{
			path[dir_len + j + 1] = command[j];
			j++;
		}
		path[total_len + 1] = '\0';
		ok_f = access(path, F_OK);
		ok_x = access(path, X_OK);
		if (ok_f == 0)
		{
			if (ok_x == 0)
				return (path);
			free(path);
			return ("no_access");
		}
		free(path);
	}
	return (NULL);
}

/**
 * print_env - print environment variables
 * @env: array of environment variables
 */

void print_env(char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		WRITE_OUT(env[i]);
		WRITE_OUT("\n");
		i++;
	}
}
