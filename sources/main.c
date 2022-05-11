/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

void get_high_score(s_var *all)
{
    char *high_score = save_text("./high_score");

    if (high_score != NULL)
        all->max_score = my_getnbr(high_score);
    else
        all->max_score = 0;
}

void save_high_score(s_var *all)
{
    int fd = -1;
    char *temp = NULL;

    if (all->score > all->max_score) {
        fd = open("./high_score", O_WRONLY | O_CREAT, 0644);
        temp = my_return_char(all->score);
        write(fd, temp, my_strlen(temp));
    }
}

void ini_tetris(s_var *all, int argc, char **argv)
{
    get_arguments(all, argc, argv);
    all->all_parts = init_struc_parts();
    all->map = create_map(all->map_x, all->map_y);
    all->temp_map = save_matrix(all->map);
    all->map_nextpart = create_map(15, 8);
    all->map_score = create_map(30, 15);
    tetriminos_nbr(all);
    if (all->show_debug != true && all->return_value != 84) {
        init_window();
        init_colors();
        get_new_pice(all);
        all->current_part = all->next_part;
        all->x_pos = (all->map_x - all->current_part->x) / 2;
        write_current_pice(all);
        get_new_pice(all);
        get_high_score(all);
    }
}

void main2(s_var *all, int key, double ini_time, double current_time)
{
    while (all->show_debug == FALSE && all->return_value == -1 
    && all->return_value != 84) {
        erase();
        key = -1;
        manage_display(all);
        key = getch();
        manage_keys(all, key);
        current_time = time(NULL);
        all->total_time = time(NULL);
        if (get_eleapsed_time(current_time, ini_time) > (0.10 - (0.02 * all->level))
        && all->pause == false) {
            go_down(all);
            ini_time = time(NULL);
        }
        if (matcmp(all->map, all->temp_map)) {
            all->temp_map = save_matrix(all->map);
        }
        if (check_if_lost(all) == 1)
            all->return_value = 0;
    }
}

int main(int argc, char **argv)
{
    int key = -1;
    double ini_time = time(NULL);
    double current_time;
    s_var *all = init_struct();
    all->total_time = time(NULL);
    all->initial_time = time(NULL);
    ini_tetris(all, argc, argv);
    if (all->show_debug == true && all->return_value != 84) {
        print_tetrimino(all);
        all->return_value = 0;
    }
    main2(all, key, ini_time, current_time);
    if (all->show_debug != true && all->return_value != 84){
        save_high_score(all);
        endwin();
    }
    return (all->return_value);
}
