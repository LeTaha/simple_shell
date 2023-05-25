#include "main.h"
/**
 * get_line - function getline
 * Credit: Taha & Lmouch
 * Return: return line
 */
#define BUF_SIZE 1024
char *get_line(void)
{
static int lenn;
static int lenn1;
static char buffer[BUF_SIZE];
char *liine;
int liine_lenn = 0;
if (lenn1 >= lenn)
{
lenn = read(STDIN_FILENO, buffer, BUF_SIZE);
if (lenn <= 0)
{
return (NULL);
}
lenn1 = 0;
}
liine = malloc(BUF_SIZE);
while (lenn1 < lenn)
{
if (buffer[lenn1] == '\n')
{
lenn1++;
break;
}
liine[liine_lenn++] = buffer[lenn1++];
}
liine[liine_lenn] = '\0';
return (liine);
}
