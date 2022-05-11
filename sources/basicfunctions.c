/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

int my_strlen2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    i--;
    return (i);
}

char *my_revstr(char *str)
{
    char *dup = malloc(sizeof(char) * my_strlen2(str) + 2);
    int j = my_strlen2(str);
    int i = 0;

    my_memset(dup, '\0', my_strlen2(str) + 1);
    while (str[i] != '\0') {
        dup[i] = str[j];
        i++;
        j--;
    }
    dup[i] = '\0';
    return (dup);
}

char *ext_my_return_char(int nb, char *str, int neg)
{
    int i = 0;

    while (nb > 0) {
        str[i] = nb % 10 + 48;
        nb /= 10;
        i++;
    }
    if (neg == 1) {
        str[i] = '-';
        i++;

    }
    str[i] = '\0';
    return (str);
}

char *my_return_char(int nb)
{
    char *str = malloc(sizeof(char) * my_nbrlen(nb) + 1);
    int neg = 0;

    if (nb < 0) {
        neg = 1;
        nb = -nb;
    }
    if (nb == 0) {
        return ("0");
        free(str);
    }
    return (my_revstr(ext_my_return_char(nb, str, neg)));
}

int matcmp(char **matrix_1, char **matrix_2)
{
    int i = 0;

    while (matrix_1[i] != NULL) {
        if (my_strcmp(matrix_1[i], matrix_2[i]) != 0)
            return (1);
        i++;
    }
    return (0);
}
