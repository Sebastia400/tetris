/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "./../includes/library.h"

int memory_allocation_ext(char **matrix, int i, int longest)
{
    while (matrix[i] != NULL) {
        if (longest < my_strlen(matrix[i]))
            longest = my_strlen(matrix[i]);
        i++;
    }
    return (longest);
}

char **memory_allocation(char **matrix)
{
    int i = 0;
    int j = 0;
    int longest = 0;
    char **final;

    longest = memory_allocation_ext(matrix, i, longest);
    final = my_calloc(i + 2, sizeof(char *));
    i = 0;
    while (matrix[i] != NULL) {
        final[i] = my_calloc( longest + 1, sizeof(char));
        my_memset(final[i], ' ', longest);
        j = 0;
        while (matrix[i][j] != '\0') {
            final[i][j] = matrix[i][j];
            j++;
        }
        final[i++][longest] = '\0';
    }
    final[i] = NULL;
    return (final);
}

void save_tetrimino(s_var *all, char *filename)
{
    char *text = save_text(filename);
    char **raw = split_string(text, '\n');
    char **matrix = NULL;
    int *info = malloc(sizeof(int) * 3);

    if (raw == NULL)
        return;
    if (check_tetrimino(raw) == 1) {
        return;
    }
    info[0] = raw[0][0] - 48;
    info[1] = raw[0][2] - 48;
    info[2] = raw[0][4] - 48;
    matrix = delete_first_line(raw);
    if (check_size(matrix, info[0], info[1]) == 1)
        return;
    create_part(all->all_parts, memory_allocation(matrix), info);
    all->good_pieces_nbr++;
}

void tetriminos_nbr_ext(s_var *all, DIR *d, struct dirent *dir,
char *full_path)
{
    while ((dir = readdir(d)) != NULL) {
        if (string_contain(dir->d_name, ".tetrimino") == 1) {
            full_path = my_strcat("./tetriminos/", dir->d_name);
            save_tetrimino(all, full_path);
            all->pieces_nbr++;
        }
    }
}

int tetriminos_nbr(s_var *all)
{
    DIR *d;
    struct dirent *dir;
    char *full_path = "";

    d = opendir("./tetriminos");
    if (d == NULL)
        all->return_value = 84;
    if (d) {
        tetriminos_nbr_ext(all, d, dir, full_path);
        closedir(d);
    }
    if (all->good_pieces_nbr == 0 || all->pieces_nbr == 0)
        all->return_value = 84;
    return (0);
}
