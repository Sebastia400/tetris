/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

void display_pause(s_var *all)
{
    print_text("PAUSE SCREN: ", 20, 40);
    display_map(all->map_score, 40, 30);
    print_text("Score: ", 30, 25);
    print_text("High Score: ", 30, 19);
    print_text("Level: ", 30, 10);
    print_text("Time(s): ", 30, 4);
    print_num(all->score, 10, 25);
    print_num(all->max_score, 10, 19);
    print_num(all->level, 10, 10);
    print_num(all->total_time - all->initial_time, 10, 4);
}

void display_msg_resize(s_var *all)
{
    char *str = "Window too small, please resize it";

    mvprintw(LINES / 2, (COLS - my_strlen(str)) / 2, str);
}

void display_map(char **map, int x, int y)
{
    int i = 0;
    int j = 0;
    int j_len = my_strlen(map[0]);

    while (map[i] != NULL) {
        j = 0;
        while (j < j_len) {
            select_color1(map[i][j]);
            mvprintw((LINES - y) / 2 + i,
            (COLS - x) / 2 + j, "%c", map[i][j]);
            j++;
        }
        i++;
    }
}

void write_current_pice(s_var *all)
{
    int i = all->y_pos;
    int j = all->x_pos;
    int x = 0;
    int y = 0;

    while (all->current_part->orient_part[all->rotation][y] != NULL) {
        j = all->x_pos;
        x = 0;
        while (all->current_part->orient_part[all->rotation][y][x] != '\0') {
            if (all->current_part->orient_part[all->rotation][y][x] == '*')
                all->map[i][j] = '0';
            x++;
            j++;
        }
        i++;
        y++;
    }
}

void manage_display(s_var *all)
{
    if (LINES >= all->map_y && COLS >= 80) {
        if (all->pause == FALSE)
            display_screen(all);
        else
            display_pause(all);
    }
    else
        display_msg_resize(all);
}
