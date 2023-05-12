#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * main - simple shell
 * Return: 0 on success,
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	int exit_shell = 0;
	pid_t pid;

	while (!exit_shell)
	{
		printf("$ ");
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			exit_shell = 1;
		}
		else
		{
			command[strcspn(command, "\n")] = '\0';
			pid = fork();

			if (pid == 0)
			{
				execlp(command, command, NULL);
				fprintf(stderr, "%s: command not found\n", command);
				exit(EXIT_FAILURE);
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
			else
			{
				fprintf(stderr, "Error forking process\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (0);
}
