/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** mysh
*/

#include "include/my.h"

void function_cd (char **args, int index)
{
    if (my_strcmp(args[0], "cd") == 0) {
        if (index != 2) {
            perror ("84");
            return;
        }
        if (chdir(args[1]) == -1) {
            perror("84");
            exit (EXIT_FAILURE);
        }
        char *path = malloc(MAX_PATH * sizeof(char));
        if (getcwd(path, MAX_PATH) == NULL) {
            perror("84");
            exit (EXIT_FAILURE);
        }
        free(path);
        return;
    }
}

void function_exit_env (char **args)
{
    if (my_strcmp(args[0], "env") == 0) {
        char **env = __environ;
        int index = 0;
        while (env[index] != NULL) {
            my_printf ("%s\n", env[index]);
            index = index + 1;
        }
        posible_errors(args);
    }
    if (my_strcmp(args[0], "exit") == 0) {
        exit (EXIT_SUCCESS);
    }
}
