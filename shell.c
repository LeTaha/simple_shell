#include "main.h"

#define BUFF_SSIZE 4096
#define IMAX_ARGS 258

/**
 * irun_shell - run shell function
 * Credir Taha & Lmouch
 */
void irun_shell(void)
{
char *linee = NULL;
char **args;
size_t len = 0;
ssize_t read;
while (1)
{
if (isatty(0))
thom_prompt();
read = getline(&linee, &len, stdin);
if (read == -1)
{
free(linee);
exit(0);
}
args = thom_args(linee);
if (!args[0])
{
thomfree_args(args);
continue;
}
if (thom_builtin(args))
{
execute_builtinthom(args);
}
else
{
exct_commvnd(args);
}
thomfree_args(args);
}
free(linee);
}
/**
 * thomfree_args - thom free args
 * @args: arguments elements
 * Credit Taha & Lmouch
 */
void thomfree_args(char **args)
{
int i;
for (i = 0; args[i]; i++)
{
free(args[i]);
}
free(args);
}
/**
 * execute_builtinthom - execute bultin thom
 * @args: argument element
 * Credit Taha & Lmouch
 */
void execute_builtinthom(char **args)
{
if (!args || !args[0])
{
return;
}
if (strcmp(args[0], "exit") == 0)
{
exit(0);
}
else if (strcmp(args[0], "cd") == 0)
{
const char *di = args[1] ? args[1] : _getenv("HOME");
if (chdir(di) != 0)
{
perror("cd");
}
}
else if (strcmp(args[0], "env") == 0)
{
char **env;
ssize_t len;
int sf = STDOUT_FILENO;
for (env = environ; *env != NULL; env++)
{
len = strlen(*env);
if (write(sf, *env, len) != len || write(sf, "\n", 1) != 1)
{
perror("write");
break;
}
}
}
}
/**
 * thom_builtin - thom bultin function
 * @args: argument element
 * Return: arguments zero
 * Credit Taha & Lmouch
 */
int thom_builtin(char **args)
{
return (strcmp(args[0], "exit") == 0 ||
strcmp(args[0], "cd") == 0 ||
strcmp(args[0], "env") == 0);
}
/**
 * thom_args - thom args function
 * @linee: line element
 * Return: argument element
 * Credit Taha & Lmouch
 */
char **thom_args(char *linee)
{
char **args = malloc(IMAX_ARGS * sizeof(char *));
char *tkn;
int i = 0;
tkn = strtok(linee, " \t\n");
while (tkn != NULL && i < IMAX_ARGS)
{
args[i++] = strdup(tkn);
tkn = strtok(NULL, " \t\n");
}
args[i] = NULL;
return (args);
}
