/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

void restart_game(s_var *all)
{
    all->map = create_map(all->map_x, all->map_y);
    get_new_pice(all);
    all->current_part = all->next_part;
    get_new_pice(all);
    write_current_pice(all);
    all->score = 0;
    all->level = 1;
}

void quit_game(s_var *all)
{
    all->return_value = 0;
}

int check_if_lost(s_var *all)
{
    int j = 1;
    int return_value = 0;

    while (all->temp_map[1][j] != '\0') {
        if ((all->temp_map[1][j] != '0' && all->temp_map[1][j] != ' '
        && all->temp_map[1][j] != '*')) {
            return_value = 1;
        }
        j++;
    }
    return (return_value);
}

double get_eleapsed_time(double current_time, double first_time)
{
    return (current_time - first_time);
}

void pause_on_off(s_var *all)
{
    if (all->pause == true)
        all->pause = false;
    else
        all->pause = true;
}
