# 0x15. C - Simple Shell
---
## Description

During this project I will learn:
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What are a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of `main`
- How does the shell use the `PATH` to find the programs
- How to execute another program with the `execve` system call
- How to suspend the execution of a process until one of its children terminates
- What is `EOF` / “end-of-file”?

---
## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- All files will be compiled on Ubuntu 14.04 LTS
- Programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- All files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Code should use the `Betty` style. It will be checked using betty-style.pl and betty-doc.pl
- No more than 5 functions per file
- All header files should be include guarded

### Output Requirements

- Unless specified otherwise, program must have the exact same output as `sh`(`/bin/sh`) as well as the exact same error output.
- The only difference is when printing an error, the name of the program must be equivalent to `argv[0]`

### List of allowed functions and system calls

- `access` (man 2 access)
- `chdir` (man 2 chdir)
- `close` (man 2 close)
- `closedir` (man 3 closedir)
- `execve` (man 2 execve)
- `exit` (man 3 exit)
- `fork` (man 2 fork)
- `free` (man 3 free)
- `stat` (__xstat) (man 2 stat)
- `lstat` (__lxstat) (man 2 lstat)
- `fstat` (__fxstat) (man 2 fstat)
- `getcwd` (man 3 getcwd)
- `getline` (man 3 getline)
- `kill` (man 2 kill)
- `malloc` (man 3 malloc)
- `open` (man 2 open)
- `opendir` (man 3 opendir)
- `perror` (man 3 perror)
- `read` (man 2 read)
- `readdir` (man 3 readdir)
- `signal` (man 2 signal)
- `strtok` (man 3 strtok)
- `wait` (man 2 wait)
- `waitpid` (man 2 waitpid)
- `wait3` (man 2 wait3)
- `wait4` (man 2 wait4)
- `write` (man 2 write)
- `_exit` (man 2 _exit)
- `isatty` (man 3 isatty)
- `fflush` (man 3 fflush)

---
File|Task
---|---
README.md| A file containing the goal of the project and the requirements and restrictions followed while creating it
AUTHORS| A file listing the contributors to the repository
getenv_help.c | Contains the functions used to obtain and use the environment
helpers.c | Contains the _strlen, free_shell, _strcpy, _strcmp, and prompt functions
helpers_cont.c | Contains the sighelp, getline_fail, print_number, _putchar, and _strdup functions
helpers_more.c | Contains the str_concat function
holberton_shell.h | The header file containing the prototypes for each function
man_1_simple_shell.man | The manual page detailing the features of the shell
simple_shell.c | The main function from which the shell starts running
statexec.c | Contains the stat_exec and builtin functions
tok.c | A function to tokenize the user input and put it in an array

## Author
Essence Boayue & Erwin Gove