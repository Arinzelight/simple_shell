#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


/* function  prototypes */
void prompt(char **av, char **env);
int main(int ac, char **argv, char **env);

#endif
