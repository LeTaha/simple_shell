#include "main.h"
/**
 * main - simple shell
 * @argtaha : number of argument
 * @argmouch : argument
 * Return: 0 on success,
 */

int main(int argtaha, char *argmouch[])
{
	char command[MAX_COM_LEN];
	int exit_shell = 0;
	pid_t pid;

	if (argtaha < 1)
	{
		return (-1);
	}
	while (!exit_shell)
	{
		printftm("#cisfun$ ");
		if (fgetstm(command, MAX_COM_LEN, stdin) == NULL)
		{
			exit_shell = 1;
		}
		else
		{
			command[strcspn(command, "\n")] = '\0';
			pid = fork();

			if (pid == 0)
			{
				execlptm(command, command, NULL);
				fprintftm(stderr, "%s: No such file or directory\n", argmouch[0]);
				exit(EXIT_FAILURE);
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
			else
			{
				fprintftm(stderr, "Error forking process\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (0);
}
