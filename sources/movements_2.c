/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

void go_left_ext(s_var *all, int i, int j)
{
    while (all->map[i][j] != '\0') {
        if (all->map[i][j] == '0') {
            all->map[i][j - 1] = '0';
            all->map[i][j] = ' ';
        }
        j++;
    }
}

void go_left(s_var *all)
{
    int i = 0;
    int j = 0;

    if (left_colision(all)) {
        while (all->map[i] != NULL) {
            j = 0;
            go_left_ext(all, i, j);
            i++;
        }
        all->x_pos--;
    }
}

void go_rotate_right(s_var *all)
{
    supres_elements_array(all->map, '0', ' ');
    all->rotation++;
    if (all->rotation > 3)
        all->rotation = 0;
    write_current_pice(all);

}

void go_rotate_left(s_var *all)
{
    supres_elements_array(all->map, '0', ' ');
    all->rotation--;
    if (all->rotation < 0)
        all->rotation = 3;
    write_current_pice(all);
}

void drop_part(s_var *all)
{
    while (down_colision(all))
        go_down(all);
    go_down(all);
}
