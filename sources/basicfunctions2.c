/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

void *my_memset(void *s, int c, int n)
{
    char *tmp = NULL;
    int	i = 0;

    tmp = s;
    i = 0;
    while (i < n)
        tmp[i++] = c;
    return (tmp);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (1);
        i++;
    }
    return (0);
}

int my_getnbr(char *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return (nb * neg);
}

char *my_strdup(char *str)
{
    char *result = calloc(my_strlen(str) + 1, sizeof(char));
    int i = 0;

    while (str[i] != '\0') {
        result[i] = str[i];
        i++;
    }
    result[i] = '\0';
    return (result);
}
