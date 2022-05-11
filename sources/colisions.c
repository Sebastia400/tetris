/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

int left_colision_ext(s_var *all, int i, int j)
{
    while (all->map[i][j] != '\0') {
        if (all->map[i][j] == '0' && all->map[i][j - 1] != '0'
        && all->map[i][j - 1] != ' ')
            return (0);
        j++;
    }
    return (1);
}

int left_colision(s_var *all)
{
    int i = 0;
    int j = 0;
    int return_value = 1;

    while (all->map[i] != NULL && return_value == 1) {
        j = 0;
        return_value  = left_colision_ext(all, i, j);
        i++;
    }
    return (return_value);
}

void colide(s_var *all)
{
    int line = 0;

    convert_0_to_pice(all);
    line = check_if_line_is_full(all->map);
        if (line != -1) {
            delete_n_line(all, line);
        }
    all->current_part = all->next_part;
    get_new_pice(all);
    write_current_pice(all);
}
