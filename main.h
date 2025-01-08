#ifndef MAIN_H
#define MAIN_H
extern char **environ;

char **split_string(char *str);
void remove_newline(char *str);
void exec_command(char *command, char *program_name);
int exec_loop(char *program_name);
char *find_executable(char *str);
char *_getenv(const char *name);
int exec_no_loop(char *program_name);
void free_array(char **tokens);

#endif
