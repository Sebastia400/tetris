/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

void init_window(void)
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    nodelay(stdscr, true);
}

s_var *init_struct(void)
{
    s_var *all = malloc(sizeof(s_var));

    all->level = 1;
    all->key_left = KEY_LEFT;
    all->key_right = KEY_RIGHT;
    all->key_turn_left = 'a';
    all->key_turn_right = 's';
    all->key_drop = KEY_DOWN;
    all->key_quit = 'q';
    all->key_pause = ' ';
    all->key_restart = 'r';
    all->map_x = 20;
    all->map_y = 10;
    all->hide_next = FALSE;
    all->show_debug = FALSE;
    all->return_value = -1;
    all->pieces_nbr = 0;
    all->good_pieces_nbr = 0;
    all->pause = FALSE;
    all->all_parts = malloc(sizeof(t_info_parts));
    return (all);
}

void init_colors(void)
{
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(10, COLOR_WHITE, COLOR_BLACK);
    init_pair(11, COLOR_YELLOW, COLOR_BLACK);
}

t_info_parts *init_struc_parts(void)
{
    t_info_parts *res = malloc(sizeof(t_info_parts));

    res->next_part = NULL;
    return (res);
}

t_info_parts *ini_linked_part(char **part, int i, int *info)
{
    t_info_parts *file = malloc(sizeof(t_info_parts) * 1);

    file->orient_part = malloc(sizeof(char **) * 4);
    file->orient_part[0] = save_matrix(part);
    file->orient_part[1] = orient_part_90(part);
    file->orient_part[2] = orient_part_180(part);
    file->orient_part[3] = orient_part_90(orient_part_180(part));
    file->num_part = i;
    file->x = info[0];
    file->y = info[1];
    file->color = info[2];
    file->next_part = NULL;
    return (file);
}
