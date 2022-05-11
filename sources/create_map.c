/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

char **maplayout_ext(int x, int i, int j, char **map)
{
    for (j = 0; j < x + 2; j++) {
        map[i][j] = ' ';
        if (j == 0 || j < x + 2)
            map[i][j] = '|';
    }
}

char **maplayout(int x, int y)
{
    char **map = malloc(sizeof(char *) * y + 3);
    int i, j;

    for (int p = 0; p < y + 2; p++) {
        map[p] = malloc(sizeof(char) * x + 3);
        my_memset(map[p], '\0', x + 3);
    }

    for (j = 0; j < x + 2; j++)
        map[0][j] = '*';
    for (i = 1; i < y + 2; i++) {
        maplayout_ext(x, i, j, map);
    }
    for (j = 0; j < x + 2; j++)
        map[i][j] = '*';
    map[i] = NULL;
    return (map);
}

char **create_map(int x, int y)
{
    int i = 0;
    int i_max = y;
    int j_max = x;
    char **map = calloc(i_max + 2, sizeof(char *));
    while (i <= i_max) {
        map[i] = calloc( j_max + 3, sizeof(char));
        if (i == 0 || i == i_max) {
            my_memset(map[i], '*', j_max);
        }
        else {
            my_memset(map[i], ' ', j_max - 1);
            map[i][0] = '*';
            map[i][j_max - 1] = '*';
        }
        map[i][j_max + 1] = '\0';
        i++;
    }
    map[i] = NULL;
    return (map);
}
