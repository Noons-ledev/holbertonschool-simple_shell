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


