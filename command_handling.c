#include "shell.h"

/**
 *handle_commands - from arguments got from getline
 *@args: datastructure of type Args
 *
 *Return: void
 */

void handle_commands(Args *args)
{
	pid_t child_pid;
	int wStatus;

	child_pid = fork();
	if (child_pid == -1)
	{
		printf("Failed to fork process");
		exit(98);
	}

	if (child_pid == 0)
	{
		command_depending_on_path(args);
	}
else
{
wait(&wStatus);
}
}

/**
 *command_depending_on_path - execute depending on path
 *@args: data structure of type Args.
 *
 *Return: nothing
 */

void command_depending_on_path(Args *args)
{
	char *path;

	path = handle_path(args);
	if (path != NULL)
	{
		if (execve(path, args->argv, NULL) == -1)
		{
			printf("%s: No such file or directory\n",
args->prgm_name);

free(path);
exit(99);
		}
	}
	else
	{
		if (execve(args->argv[0]. args->argv, NULL) == -1)
		{
			printf("%s: No such file or directory\n",
args->prgm_name);
			free(path);
			exit(99);
		}
	}
	free(path);
}
