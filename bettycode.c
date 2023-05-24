#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * prompt - Display the shell prompt
 */
void prompt(void)
{
	printf("#cisfun$ ");
}

/**
 * execute_command - Execute the given command
 * @command: The command to execute
 */
void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execlp(command, command, (char *)NULL) == -1)
		{
			printf("Command not found: %s\n", command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}

/**
 * main - Entry point of the shell program
 *
 * Return: 0 on success
 */
int main(void)
{
	char buffer[BUFFER_SIZE];

	while (1)
	{
		prompt();

		if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
		{
			break;
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		execute_command(buffer);
	}

	return (0);
}
