/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

void get_new_pice(s_var *all)
{
    all->next_part = rand_next_part(all, all->all_parts);
    all->x_pos = ((my_strlen(all->map[0]) / 2) - (all->next_part->x / 2));
    all->y_pos = 1;
    all->rotation = 0;
}

int check_if_line_is_full_ext(char **map, int i)
{
    int j = 0;
    int len = 0;

    while (map[i][j] != '\0') {
        if (map[i][j] > '0' && map[i][j] <= '9')
            len++;
        if (len == my_strlen(map[0]) - 2)
            return (i);
        j++;
    }
    return (-1);
}

int check_if_line_is_full(char **map)
{
    int i = 1;
    int line = -1;
    int len = 0;

    while (map[i + 1] != NULL) {
        line = check_if_line_is_full_ext(map, i);
        if (line != -1)
            return (line);
        i++;
    }
    return (-1);
}

void delete_n_line(s_var *all, int n)
{
    int i = 0;
    char *temp = malloc(sizeof(char) * (my_strlen(all->map[0]) + 1));
    my_memset(temp, '\0', my_strlen(all->map[0]) + 1);

    for (i = 0; i < my_strlen(all->map[0]); i++) {
        temp[i] = ' ';
        if (i == 0 || i == my_strlen(all->map[0]) - 1)
            temp[i] = '*';
    }
    while (n - 1 > 1) {
        all->map[n] = all->map[n - 1];
        n--;
    }
    all->score += 100;
    if ((all->score / 100) % 10 == 0)
        all->level++;
    all->map[n] = temp;
}
