/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

char **orient_part_180(char **matrix)
{
    int i = matrix_len(matrix);
    int j = 0;
    char **result = my_calloc(i + 3, sizeof(char *));
    while (i >= 0)
        result[j++] = my_revstr(my_strdup(matrix[i--]));
    result[j] = NULL;
    return (result);
}

void my_array_set(char **result, int y, int i, int j)
{
    while (y <= j) {
        result[y] = malloc((i + 10) * sizeof(char));
        result[y] = my_memset(result[y], '\0', i + 10);
        y++;
    }
}

char **orient_part_90(char **matrix)
{
    int i = matrix_len(matrix);
    int j = my_strlen(matrix[0]);
    char **result = malloc((i + 10) * sizeof(char *));
    int x = 0;
    int y = 0;

    my_array_set(result, y, i, j);
    x = 0;
    while (i >= 0) {
        y = 0;
        while (matrix[i][y] != '\0') {
            result[y][x] = matrix[i][y];
            y++;
        }
        x++;
        i--;
    }
    result[y] = NULL;
    return (result);
}

void create_part(t_info_parts *parts, char **part, int *info)
{
    t_info_parts *tmp_parts = parts;
    int j = 0;

    while (tmp_parts->next_part != NULL) {
        j++;
        tmp_parts = tmp_parts->next_part;
    }
    tmp_parts->next_part = ini_linked_part(part, j, info);
}

t_info_parts *rand_next_part(s_var *all, t_info_parts *parts)
{
    t_info_parts *tmp = parts->next_part;
    int rand_num = rand() % all->good_pieces_nbr;

    while (tmp != NULL) {
        if (tmp->num_part == rand_num)
            return (tmp);
        tmp = tmp->next_part;
    }
    return (tmp);
}
