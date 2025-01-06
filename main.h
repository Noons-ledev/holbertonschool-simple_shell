#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
extern char **environ;

void remove_newline(char *str);
char **split_string(char *str);
int comm_exec(char **command);
char *find_command_path(char *command);
char *_getenv(const char *name);
int exec_loop(void);
int exec_no_loop(void);
void exec_command(char *command);

#endif

