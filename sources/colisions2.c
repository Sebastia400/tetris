/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

int down_colision_ext(s_var *all, int i, int j)
{
    while (all->map[i][j] != '\0') {
        if (all->map[i][j] == '0' && all->map[i + 1][j] != '0'
        && all->map[i + 1][j] != ' ')
            return (0);
        j++;
    }
    return (1);
}

int down_colision(s_var *all)
{
    int i = 0;
    int j = 0;
    int return_value = 1;

    while (all->map[i] != NULL && return_value == 1) {
        j = 0;
        return_value = down_colision_ext(all, i, j);
        i++;
    }
    return (return_value);
}

int right_colision_ext(s_var *all, int i, int j)
{
    while (all->map[i][j] != '\0') {
        if (all->map[i][j] == '0' && all->map[i][j + 1] != '0'
        && all->map[i][j + 1] != ' ')
            return (0);
        j++;
    }
    return (1);
}

int right_colision(s_var *all)
{
    int i = 0;
    int j = 0;
    int return_value = 1;

    while (all->map[i] != NULL && return_value == 1) {
        j = 0;
        return_value = right_colision_ext(all, i , j);
        i++;
    }
    return (return_value);
}
