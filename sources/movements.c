/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

void go_down_ext(s_var *all, int i, int j)
{
    while (all->map[i][j] != '\0') {
        if (all->map[i][j] == '0'){
            all->map[i + 1][j] = '0';
            all->map[i][j] = ' ';
        }
        j++;
    }
}

void go_down(s_var *all)
{
    int i = matrix_len(all->map);
    int j = 0;
    if (down_colision(all)) {
        while (i > 0) {
            j = 0;
            go_down_ext(all, i, j);
            i--;
        }
        all->y_pos++;
    }
    else
        colide(all);
}

void go_right_ext(s_var *all, int i, int j)
{
    while (j > 0) {
        if (all->map[i][j] == '0') {
            all->map[i][j + 1] = '0';
            all->map[i][j] = ' ';
        }
        j--;
    }
}

void go_right(s_var *all)
{
    int i = 0;
    int j = all->map_x;

    if (right_colision(all)) {
        while (all->map[i] != NULL) {
            j = all->map_x;
            go_right_ext(all, i, j);
            i++;
        }
        all->x_pos++;
    }
}
