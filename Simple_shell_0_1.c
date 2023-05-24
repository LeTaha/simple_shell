#include "main.h"
/**
 * shell_loop - Run the shell loop
 */
void shell_loop(void)
{
	char *input;
	char **args;
	int status;

	do {
		printf("$ ");
		input = read_input();
		args = split_input(input);
		status = execute(args);

		free(input);
		free(args);
	} while (status);
}
/**
 * execute - Execute the given command
 * @args: The array of arguments
 *
 * Return: The status of the execution
 */
int execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
