#include "main.h"

char *fgetstm(char *str, int size, FILE *stream)
{
	int i;
	int ch;

	if (size <= 0 || str == NULL || stream == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size - 1; i++)
	{
		ch = fgetc(stream);
		if (ch == EOF)
		{
			break;
		}
		str[i] = (char)ch;
		if (ch == '\n')
		{
			i++;
			break;
		}
	}
	str[i] = '\0';
	if (i == 0 && ch == EOF)
	{
		return (NULL);
	}
	return (str);
}
int printftm(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	count = vprintf(format, args);

	va_end(args);
	return (count);
}
int fprintftm(FILE *stream, const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	count = vfprintf(stream, format, args);
	va_end(args);
	return (count);
}
int execlptm(const char *file, const char *arg, ...)
{
	va_list args;
	const char *current_arg;
	int count = 0;
	int i;
	char **args_array;

	va_start(args, arg);
	current_arg = arg;
	while (current_arg != NULL)
	{
		count++;
		current_arg = va_arg(args, const char *);
	}
	va_end(args);

	args_array = (char **)malloc((count + 2) * sizeof(char *));
	if (args_array == NULL)
	{
		return (-1);
	}

	args_array[0] = (char *)file;
	current_arg = arg;
	for (i = 1; i <= count; i++)
	{
		args_array[i] = (char *)current_arg;
		current_arg = va_arg(args, const char *);
	}
	args_array[count + 1] = NULL;

	execvp(file, args_array);
	free(args_array);

	return (-1);
}
