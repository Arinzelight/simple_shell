#include "main.h"     
#define MAX_COMMAND 10

void prompt(char **av, char **env)
{
        char *lineptr = NULL;
        int i, j, status;
        size_t n = 0;
        size_t line_char;
        pid_t child_pid;
        char *prompt = "(Bshell) $ ";
        char *argv[MAX_COMMAND];
        const char *delim = " ";
        while (1)
        {
                if(isatty(STDIN_FILENO))
                printf("%s", prompt);
                line_char = getline(&lineptr, &n, stdin);
                /* check if getline function failed or returned EOF or user entered CTR+D */
                if (line_char == -1)
                {
                        free(lineptr);
                        exit(EXIT_FAILURE);
                }

                i = 0;
                while (lineptr[i])
                {
                        if (lineptr[i] == '\n')
                        {
                                lineptr[i] = 0;
                        }
                        i++;
                }

                /* tokenizatiion to split commands*/
                j = 0;
                argv[j] = strtok(lineptr, delim);
                while (argv[j] != NULL)
                        argv[++j] = strtok(NULL, delim);

                child_pid = fork();
                if (child_pid == -1)
                {
                        free(lineptr);
                        exit(EXIT_FAILURE);
                 }
                if (child_pid == 0 && (execve(argv[0], argv, env)) == -1)
                {
                        printf("%s: No such file or directory\n", av[0]);
                }
                else
                {
                        wait(&status);
                }
        }
}
