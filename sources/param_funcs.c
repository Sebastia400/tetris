/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

int param_level(s_var *all, int argc, char **argv, int i)
{
    char **params = NULL;

    if (i >= argc)
        return (i);
    if (is_char_in_str('=', argv[i]) == 1) {
        params = split_string(argv[i], '=');
        if (my_strcmp(params[0], "--level") == 0 && is_number(params[1]) == 1)
            all->level = my_getnbr(params[1]);
        else if (my_strcmp(params[0], "--level") == 0 && is_number(params[1])
         == 0)
            all->return_value = 84;
    } else {
        if (my_strcmp(argv[i], "-L") == 0 && i + 1 < argc && is_number(argv[i 
        + 1]) == 1)
            all->level = my_getnbr(argv[i + 1]);
        else if (my_strcmp(argv[i], "-L") == 0 && (i + 1 >= argc 
        || is_number(argv[i + 1]) == 0))
            all->return_value = 84;
    }
    return (i);
}

int param_left_key(s_var *all, int argc, char **argv, int i)
{
    char **params = NULL;

    if (i >= argc)
        return (i);
    if (is_char_in_str('=', argv[i]) == 1) {
        params = split_string(argv[i], '=');
        if (my_strcmp(params[0], "--key-left") == 0 && is_number(params[1]) 
        == 1)
            all->key_left = my_getnbr(params[1]);
        else if (my_strcmp(params[0], "--key-left") == 0 
        && is_number(params[1]) != 1)
            all->return_value = 84;
    } else {
        if (my_strcmp(argv[i], "-l") == 0 && i + 1 < argc && is_number(argv[i 
        + 1]) == 1)
            all->key_left = my_getnbr(argv[i + 1]);
        else if (my_strcmp(argv[i], "-l") == 0 && (i + 1 >= argc || is_number(
        argv[i + 1]) != 1))
            all->return_value = 84;
    }
    return (i);
}

int param_right_key(s_var *all, int argc, char **argv, int i)
{
    char **params = NULL;

    if (i >= argc)
        return (i);
    if (is_char_in_str('=', argv[i]) == 1) {
        params = split_string(argv[i], '=');
        if (my_strcmp(params[0], "--key-right") == 0 && is_number(params[1]) 
        == 1)
            all->key_right = my_getnbr(params[1]);
        else if (my_strcmp(params[0], "--key-right") == 0 
        && is_number(params[1]) != 1)
            all->return_value = 84;
    } else {
        if (my_strcmp(argv[i], "-r") == 0 && i + 1 < argc && is_number(argv[i 
        + 1]) == 1)
            all->key_right = my_getnbr(argv[i + 1]);
        else if (my_strcmp(argv[i], "-r") == 0 && (i + 1 >= argc 
        || is_number(argv[i + 1]) != 1))
            all->return_value = 84;
    }
    return (i);
}

int param_turn_key(s_var *all, int argc, char **argv, int i)
{
    char **params = NULL;

    if (i >= argc)
        return (i);
    if (is_char_in_str('=', argv[i]) == 1) {
        params = split_string(argv[i], '=');
        if (my_strcmp(params[0], "--key-turn") == 0 && is_number(params[1]) 
        == 1)
            all->key_turn_right = my_getnbr(params[1]);
        else if (my_strcmp(params[0], "--key-turn") == 0 && is_number(
            params[1]) != 1)
            all->return_value = 84;
    } else {
        if (my_strcmp(argv[i], "-t") == 0 && i + 1 < argc && is_number(
            argv[i + 1]) == 1)
            all->key_turn_right = my_getnbr(argv[i + 1]);
        else if (my_strcmp(argv[i], "-t") == 0 && (i + 1 >= argc || is_number(
            argv[i + 1]) != 1))
            all->return_value = 84;
    }
    return (i);
}

int param_drop_key(s_var *all, int argc, char **argv, int i)
{
    char **params = NULL;

    if (i >= argc)
        return (i);
    if (is_char_in_str('=', argv[i]) == 1) {
        params = split_string(argv[i], '=');
        if (my_strcmp(params[0], "--key-drop") == 0 && is_number(params[1]) 
        == 1)
            all->key_drop = my_getnbr(params[1]);
        else if (my_strcmp(params[0], "--key-drop") == 0 
        && is_number(params[1]) != 1)
            all->return_value = 84;
    } else {
        if (my_strcmp(argv[i], "-d") == 0 && i + 1 < argc && is_number(argv[i 
        + 1]) == 1)
            all->key_drop = my_getnbr(argv[i + 1]);
        else if (my_strcmp(argv[i], "-d") == 0 && (i + 1 >= argc 
        || is_number(argv[i + 1]) != 1))
            all->return_value = 84;
    }
    return (i);
}
