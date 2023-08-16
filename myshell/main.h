#ifndef SHELL_H
#define SHELL_H

/*------LIBRARIES-------*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>


/*------PROTOTYPES--------*/
void interactive_mode(void);
void non_interactive_mode(void);
char *read_input(void);
char **line_split(char *line_string);
int exec_args(char **args);
char *read_stream(void);
int new_process(char **args);
char *read_line(void);
int main(void);
/*-------MACROS--------*/
#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

/*-------BUILTIN FUNCTIONS-----*/
int my_cd(char **args);
int env(char **args);
int my_exit(char **args);


#endif
