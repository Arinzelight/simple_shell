0x16. C - Simple Shell

This is a simple shell project that implements a basic command-line interface, allowing users to interact with the system by executing various commands. The shell supports both interactive and non-interactive modes, providing a user-friendly interface for running commands and managing processes.

Features
*Interactive and Non-Interactive Modes: The shell can be run interactively, where it displays a prompt for users to input commands one by one. It can also be used in non-interactive mode, where commands are provided as arguments, allowing for script-based execution.

*Command Execution: The shell supports execution of a wide range of system commands. It can execute external programs and built-in commands.

*Built-in Commands: Certain commands are built directly into the shell and are executed without creating a separate process. Examples of built-in commands include exit, which terminates the shell, and cd, which changes the current working directory.

*Process Management: The shell can create, manage, and monitor processes using system calls like fork, execve, and process control functions like wait and waitpid.

*File System Interaction: Various file-related operations are supported, such as opening, reading, and writing files. Additionally, the shell can manipulate directories, read directory contents, and access file status information.


Allowed Functions
The following system calls and library functions are allowed for use in this project:

access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

Compilation
this shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Run the compiled executable:

./hsh


Usage Examples

Interactive Mode:

$ ./hsh
($) /bin/ls
cd.c   exec_args.c  hsh                 line_split.c  main.h         non_interactive.c  read_line.c  stirngs.c  TEST_SUITE
env.c  exit.c       interactive_mode.c  main.c        new_process.c  read_input.c       README.md    string.c   which_path.c
$ 
($)
($) exit
$

Non-Interactive Mode:
$ echo "/bin/ls" | ./hsh
cd.c   exec_args.c  hsh                 line_split.c  main.h         non_interactive.c  read_line.c  stirngs.c  TEST_SUITE
env.c  exit.c       interactive_mode.c  main.c        new_process.c  read_input.c       README.md    string.c   which_path.c
$



Credits
This project was created by [EZINWA ARINZE &  Chiamaka Ogbodo] as a part of [C-low_level programme/Project] at [ALX].
