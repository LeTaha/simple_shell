#include "main.h"

/**
 * pnt_iid - print ID function
 * Credit Taha & Lmouch
 */
void pnt_iid(void)
{
char pid_str[100];
int pid_len;

pid_len = sprintf(pid_str, "PID: %d\n", getpid());
write(STDOUT_FILENO, pid_str, pid_len);
}
/**
 * pnt_iiid - print Prent ID function
 * Credit Taha & Lmouch
 */
void pnt_iiid(void)
{
char ppid_str[100];
int ppid_len;

ppid_len = sprintf(ppid_str, "PPID: %d\n", getppid());
write(STDOUT_FILENO, ppid_str, ppid_len);
}
