/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

void convert_0_to_pice_ext(s_var *all, int i, int j)
{
    while (all->map[i][j] != '\0') {
        if (all->map[i][j] == '0')
            all->map[i][j] = all->current_part->color + 48;
        j++;
    }
}

void convert_0_to_pice(s_var *all)
{
    int i = 0;
    int j = 0;

    while (all->map[i] != NULL) {
        j = 0;
        convert_0_to_pice_ext(all, i, j);
        i++;
    }
}

void supres_elements_array_ext(char **array, char c, char d, int i)
{
    int j = 0;

    while (array[i][j] != '\0') {
        if (array[i][j] == c)
            array[i][j] = d;
        j++;
    }
}

void supres_elements_array(char **array, char c, char d)
{
    int i = 0;

    while (array[i] != NULL) {
        supres_elements_array_ext(array, c, d, i);
        i++;
    }
}
