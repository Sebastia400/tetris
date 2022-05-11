/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

int param_quit_key(s_var *all, int argc, char **argv, int i)
{
    char **params = NULL;

    if (i >= argc)
        return (i);
    if (is_char_in_str('=', argv[i]) == 1) {
        params = split_string(argv[i], '=');
        if (my_strcmp(params[0], "--key-quite") == 0
        && is_number(params[1]) == 1)
            all->key_quit = my_getnbr(params[1]);
        else if (my_strcmp(params[0], "--key-quite") == 0
        && is_number(params[1]) != 1)
            all->return_value = 84;
    } else {
        if (my_strcmp(argv[i], "-q") == 0 && i + 1 < argc
        && is_number(argv[i + 1]) == 1)
            all->key_quit = my_getnbr(argv[i + 1]);
        else if (my_strcmp(argv[i], "-q") == 0 && (i + 1 >= argc
        && is_number(argv[i + 1]) != 1))
            all->return_value = 84;
    }
    return (i);
}

int param_pause_key(s_var *all, int argc, char **argv, int i)
{
    char **params = NULL;

    if (i >= argc)
        return (i);
    if (is_char_in_str('=', argv[i]) == 1) {
        params = split_string(argv[i], '=');
        if (my_strcmp(params[0], "--key-pause") == 0
        && is_number(params[1]) == 1)
            all->key_pause = my_getnbr(params[1]);
        else if (my_strcmp(params[0], "--key-pause") == 0
        && is_number(params[1]) != 1)
            all->return_value = 84;
    } else {
        if (my_strcmp(argv[i], "-p") == 0 && i + 1 < argc
        && is_number(argv[i + 1]) == 1)
            all->key_pause = my_getnbr(argv[i + 1]);
        else if (my_strcmp(argv[i], "-p") == 0 && (i + 1 >= argc
        && is_number(argv[i + 1]) != 1))
            all->return_value = 84;
    }
    return (i);
}

int param_map_size(s_var *all, int argc, char **argv, int i)
{
    char **params = NULL;
    char **lenght = NULL;

    if (i >= argc)
        return (i);
    if (is_char_in_str('=', argv[i]) == 1) {
        params = split_string(argv[i], '=');
        if (my_strcmp(params[0], "--key-pause") == 0) {
            lenght = split_string(params[1], ',');
            if (is_number(lenght[0]) == 1 && is_number(lenght[1]) == 1) {
                all->map_x = my_getnbr(lenght[0]);
                all->map_y = my_getnbr(lenght[1]);
            }
        }
        return (i + 1);
    }
    return (i);
}
