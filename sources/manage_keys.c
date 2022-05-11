/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

void fill_flags(struct_pages *flags, s_var *all)
{
    flags[0].op = all->key_left;
    flags[0].ptr = &go_left;
    flags[1].op = all->key_right;
    flags[1].ptr = &go_right;
    flags[2].op = all->key_turn_right;
    flags[2].ptr = &go_rotate_right;
    flags[3].op = all->key_turn_left;
    flags[3].ptr = &go_rotate_left;
    flags[4].op = all->key_restart;
    flags[4].ptr = &restart_game;
    flags[5].op = all->key_quit;
    flags[5].ptr = &quit_game;
    flags[6].op = all->key_drop;
    flags[6].ptr = &drop_part;
    flags[7].op = all->key_pause;
    flags[7].ptr = &pause_on_off;
}

void manage_keys(s_var *all, int key_pressed)
{
    int i = 0;

    struct_pages flags[8];
    fill_flags(flags, all);
    while (i < 8) {
        if (key_pressed == flags[i].op)
            (*(flags[i].ptr))(all);
        i++;
    }
}
