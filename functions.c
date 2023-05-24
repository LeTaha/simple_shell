#include "main.h"
/**
 * read_input - Read input from the user
 *
 * Return: The input string
 */
char *read_input()
{
	char *input = NULL;
	size_t bufsize = 0;

	getline(&input, &bufsize, stdin);
	return (input);
}
/**
 * split_input - Split the input string into an array of arguments
 * @input: The input string to split
 *
 * Return: The array of arguments
 */
char **split_input(char *input)
{
	int bufsize = TOKEN_BUFFER_SIZE;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
	fprintf(stderr, "Allocation error\n");
	exit(EXIT_FAILURE);
	}

	token = strtok(input, TOKEN_DELIMITERS);
	while (token != NULL)
	{
	tokens[position] = token;
	position++;

	if (position >= bufsize)
	{
	bufsize += TOKEN_BUFFER_SIZE;
	tokens = realloc(tokens, bufsize * sizeof(char *));
	if (!tokens)
	{
	fprintf(stderr, "Allocation error\n");
	exit(EXIT_FAILURE);
	}
	}

	token = strtok(NULL, TOKEN_DELIMITERS);
	}
	tokens[position] = NULL;
	return (tokens);
}
