#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void remove_newline(char *str);
char **split_string(char *str);
int comm_exec(char **command);
char *find_command_path(char *command);

#endif
