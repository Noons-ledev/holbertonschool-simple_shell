## NAME

  simple shell

## SYNOPSIS

  #include "main.h"
  int main(int argc, char **argv)

## PROTOTYPE
```C
  int main(int argc, char **argv);
  void exec_command(char *command, char *program_name);
  int exec_loop(char *program_name);
  int exec_no_loop(char *program_name);
  char *find_executable(char *str);
  void printenv(void);
  char **split_string(char *str);
  void remove_newline(char *str);
  char *_getenv(const char *name);
  void free_array(char **tokens);
  size_t _strspn(char *str, char *models);
```
## DESCRIPTION

  Un shell est une interface en ligne de commande qui permet à l'utilisateur
  d'interagir avec le système d'exploitation. Simple shell est un shell basique
  qui offre les fonctionnalités essentielles:

  Exécution de commandes de base (ls, cd, pwd, etc.)
  Gestion des processus en arrière-plan avec &
  Redirection des entrées/sorties avec > et
  Support des pipelines avec |
  Gestion des variables d'environnement

  C'est un shell minimaliste, parfait pour comprendre les concepts fondamentaux
  des interfaces en ligne de commande.

## COMPILATION AND EXECUTION

  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
  ./hsh

## COMMAND EXEMPLE

  ```bash
  #cisfun$ ls
  AUTHORS.md  README.md  executables.c  function_tools.c  hsh  main.c  main.h
  ```

  ```bash
  #cisfun$ pwd
  /holbertonschool-simple_shell
  ```

## RETURN VALUE

  returns NULL if it fails and 0 if successful

## ERRORS EXEMPLE

  malloc errors, getline error, token NULL, if an error occurs, the corresponding
  function will return NULL

## AUTHORS

  BRIET Noah

## SEE ALSO

  Source code available at: <https://github.com/Noons-ledev/holbertonschool-simple_shell/blob/noah>
