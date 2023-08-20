#ifndef SHELL_H
#define SHELL_H

/*------LIBRARIES-------*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

/*------PROTOTYPES--------*/
void interactive_mode(void);
void non_interactive_mode(void);
char *read_input(void);
char **line_split(char *line_string);
int exec_args(char **args);
char *read_stream(void);
int new_process(char **args, int cmd_num);
char *read_line(void);
int main(void);
char *find_path(char *arg);
void print_err(int cmd_no, char *prog_name);
int print_num(unsigned int n);


/*-------MACROS--------*/
#define TOK_DELIM " \t\r\n\a\""
#define PROMPT "$ "

extern char **environ;
extern char *prog_name;
extern int cmd_num;


/*-------BUILTIN FUNCTIONS-----*/
int my_cd(char **args);
int env(char **args);
int my_exit(char **args);

/*-------STRING MANUPULATION----*/
char *str_cat(char *dest, char *src);
char *str_cpy(char *dest, char *src);
char *str_dup(char *s);
int str_len(char *str);
int str_cmp(char *s1, char *s2);
int _putstr(char *str, int fd);
int _putchar(char z);

extern char **environ;


#endif
