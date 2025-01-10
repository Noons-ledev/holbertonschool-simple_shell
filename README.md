# Simple Shell (C, eng)


Simple shell is a UNIX like based command interpreter. 
It, as the models it follows, can reproduce some of the basic commands of a shell, taking argument in counts.
(i.e ls, pwd, echo, cat, etc...)
-

## Installation
To start off you'll have to clone the repository :
```bash
 git clone https://github.com/Noons-ledev/holbertonschool-simple_shell
 ```
## Compilation
To compile the program you'll need to go to the directory where the repository was cloned : 
```bash
cd holbertonschool-simple_shell
```
Then use gcc within the following command :
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage
Once compiled, you can now start your shell with 
```bash
./hsh
```
## Memory Handling
As you can see below, our program has been memory managed with valgrind, ensuring to perform safely and without any leaks
You can also check it by going :
```bash
valgrind --leak -check=full ./hsh
```
And once you'll exit the program you'll be able to see that nothing wrong is happening on the memory scope.
![image](https://github.com/user-attachments/assets/311da307-1b47-4115-9d46-5c7c08e16a65)

## Flowchart

Here is the flowchart made to realise the whole project, shortcuting how it works

![SimpleShell (1)](https://github.com/user-attachments/assets/9bc89b63-3a24-4bd1-93a8-2ed07d134135)

## Modes

This SimpleShell implementation works in both interactive

![Capture d’écran 2025-01-10 à 09 36 56](https://github.com/user-attachments/assets/50d814a3-3865-4922-bf51-29eca7b6097d)

and non interactive mode

![Capture d’écran 2025-01-10 à 09 39 13](https://github.com/user-attachments/assets/4e2dbbea-8a3b-4c7e-b21e-a1feab76dbaf)

## Implementations
Here are the different functions prototypes used to achieve this project:
```C
char **split_string(char *str);
void remove_newline(char *str);
void exec_command(char *command, char *program_name);
int exec_loop(char *program_name);
char *find_executable(char *str);
char *_getenv(const char *name);
int exec_no_loop(char *program_name);
void free_array(char **tokens);
size_t _strspn(char *str, char *models);
void printenv(void);
int main(int argc, char**argv);
```
## Contributors
Noah Briet
