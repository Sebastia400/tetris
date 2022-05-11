/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

void print_map(char **map, int x, int y)
{
    int i = 0;

    while (map[i] != NULL) {
        mvprintw((LINES - y) / 2 + i, (COLS - x) / 2, map[i]);
        i++;
    }
}

void print_text(char *map, int x, int y)
{
    mvprintw((LINES - y) / 2, (COLS - x) / 2, map);
}

void print_num(int num, int x, int y)
{
    mvprintw((LINES - y) / 2, (COLS - x) / 2, "%d", num);
}

void print_next_part(t_info_parts *parts, int x, int y)
{
    char **map = parts->orient_part[0];
    int i = 0;
    int j = 0;
    int j_len = my_strlen(map[0]);

    while (map[i] != NULL) {
        j = 0;
        while (j < j_len) {
            if (map[i][j] != ' ')
                attron(COLOR_PAIR(parts->color));
            else
                attron(COLOR_PAIR(11));
            mvprintw((LINES - y) / 2 + i,
            (COLS - x) / 2 + j, "%c", map[i][j]);
            j++;
        }
        i++;
    }
}

void display_screen(s_var *all)
{
    display_map(all->map, 50, 40);
    display_map(all->map_score, 120, 0);
    print_text("Score: ", 110, -5);
    print_text("High Score: ", 110, -10);
    print_text("Lines: ", 110, -14);
    print_text("Level: ", 110, -18);
    print_text("Time(s): ", 110, -22);
    print_num(all->score, 80, -5);
    print_num(all->max_score, 80, -10);
    print_num((all->score / 100), 80, -14);
    print_num(all->level, 80, -18);
    print_num(all->total_time - all->initial_time, 80, -22);
    print_text("SEBASTIA I VICTOR", -70, -50);
    if (all->hide_next == false) {
        print_text("NEXT PART:", -45, 43);
        display_map(all->map_nextpart, -40, 40);
        print_next_part(all->next_part, -55, 36);
    }
}
