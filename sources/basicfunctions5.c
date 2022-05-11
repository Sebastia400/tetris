/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

int size_text(char *filepath)
{
    struct stat buf;
    stat(filepath, &buf);
    return (buf.st_size);
}

char *save_text(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    long size = size_text(filepath);
    char *arraytext = NULL;

    if (fd == -1)
        return (NULL);
    arraytext = malloc(sizeof(char) * size + 1);
    my_memset(arraytext, '\0', size + 1);
    read(fd, arraytext, size);
    close(fd);
    return (arraytext);
}

int my_arraylen(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    return (i);
}

char **delete_first_line(char **array)
{
    int i = 1;
    int j = 0;
    char **temp = malloc(sizeof(char *) * my_arraylen(array));

    while (array[i] != NULL) {
        temp[j] = my_strdup(array[i]);
        i++;
        j++;
    }
    temp[j] = NULL;
    return (temp);
}

int check_valid_char(char **matrix)
{
    int i = 1;
    int j = 0;

    while (matrix[i] != NULL) {
        j = 0;
        while (matrix[i][j] != '\0') {
            if (matrix[i][j] != '*' && matrix[i][j] != ' ')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
