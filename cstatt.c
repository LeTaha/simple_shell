#include "main.h"
/**
 * prt_fle_stt - promt file state
 * @file_name: file name
 * Return: return file name
 * Credit Taha & Lmouch
 */
void prt_fle_stt(char *file_name)
{
struct stat file_stat;
char buffer[1024];
int len;
if (stat(file_name, &file_stat) == -1)
{
perror("stat");
return;
}
len = sprintf(buffer, "File: %s\n", file_name);
write(STDOUT_FILENO, buffer, len);

}
