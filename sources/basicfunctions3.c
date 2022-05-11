/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

int matrix_len(char **matrix)
{
    int len = 0;

    while (matrix[len] != NULL)
        len++;
    return (len - 1);
}

char **save_matrix(char **matrix)
{
    int i = 0;
    char **temp = my_calloc(matrix_len(matrix) + 2, sizeof(char *));

    while (matrix[i] != NULL) {
        temp[i] = my_strdup(matrix[i]);
        i++;
    }
    temp[i] = NULL;
    return (temp);
}

char *my_strcat(char *dest, char *src)
{
    char *temp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)) + 2);
    int i = 0;
    int n = 0;

    my_memset(temp, '\0', (my_strlen(dest) + my_strlen(src)) + 2);
    while (dest[i] != '\0') {
        temp[i] = dest[i];
        i++;
    }
    while (src[n] != '\0') {
        temp[i] = src[n];
        i++;
        n++;
    }
    temp[i] = '\0';
    return (temp);
}

void *my_calloc(int nmemb, int size)
{
    void *ptr = NULL;

    if (!(ptr = malloc(nmemb * size)))
        return (NULL);
    ptr = my_memset(ptr, 0, nmemb * size);
    return (ptr);
}

int my_nbrlen(int nb)
{
    int len = 0;

    if (nb == 0)
        return (1);
    while (nb > 0) {
        nb /= 10;
        len++;
    }
    return (len);
}
