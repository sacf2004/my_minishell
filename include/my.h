/*
** EPITECH PROJECT, 2023
** My_ls
** File description:
** All functions used
*/

#ifndef _LS_H
    #define _LS_H
    #define MAX_INPUT 100
    #define MAX_PATH 10000
    #include <dirent.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <wait.h>
    #include "../printf/lib/my/include/myprintf.h"


int my_strcmp (char const *s1, char const *s2);

char *my_strcat (char *dest, char const *src);

int my_ls_l (DIR *dir);

int my_ls_r (char const *files);

int my_ls_a(const char *files);

void start_print_date(char *str, int pos);

char my_ls_normal_with_path (int ac, char **av);

char my_ls_r_may (char const *files);

char my_ls_r_may_with_path(int ac, char **av);

int my_ls_l_with_path (int ac, char **av);

char my_ls_r_may_help (const char *path);

char **my_str_to_word_array(const char *str);

void posible_errors (char **args);

void function_cd (char **args, int index);

void function_setenv (char **args, char *words);

void function_exit_env (char **args);

#endif
