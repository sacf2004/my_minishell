/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** mysh
*/

#include "include/my.h"
#include <stdlib.h>

void posible_errors (char **args)
{
    pid_t child_pid = fork();
    int status;
    if (child_pid == -1) {
        perror("84");
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0) {
        if (execve(args[0], args, NULL) == -1) {
            perror("84");
            exit(EXIT_FAILURE);
        }
    } else {
        pid_t pid = waitpid(child_pid, &status, 0);
        if (pid == -1) {
            perror("84");
            exit(EXIT_FAILURE);
        }
    }
}

void help (char *words)
{
    while (1) {
        my_printf("$> ");
        int len = read(0, words, MAX_INPUT);
        words[len - 1] = '\0';
        if (len <= 0) {
            my_printf ("\n");
            exit(EXIT_FAILURE);
        }
        if (my_str_count_len(words) >= MAX_INPUT ||
            my_str_count_len(words) == 0
            || words[len - 2] == '\r' )
            my_printf ("");
        else
            break;
    }
}

void loop (void)
{
    char *words = malloc(MAX_INPUT * sizeof(char));
    while (1) {
        help (words);
        char *arguments[] = {"/bin/sh", "-c", words, NULL};
        posible_errors(arguments);
        char *token = strtok(words, " "), *args[100];
        int index = 0;
        while (token != NULL) {
            args[index] = token;
            index = index + 1;
            token = strtok(NULL, " ");
        }
        args[index] = NULL;
        function_cd(args, index);
        function_exit_env(args);
    }
    free(words);
}

int main (int ac, char **av)
{
    loop();
    return 0;
}
