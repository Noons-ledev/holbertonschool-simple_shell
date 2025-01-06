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
int exec_loop(char *program_name);
int exec_no_loop(char *program_name);
void exec_command(char *command, char *program_name);

#endif

