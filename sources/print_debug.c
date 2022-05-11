/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

char *return_key(int key)
{
    char *str = malloc(sizeof(char) * 2);

    str[1] = '\0';
    if (key == KEY_LEFT)
        return ("KEY_LEFT");
    if (key == KEY_RIGHT)
        return ("KEY_RIGHT");
    if (key == KEY_UP)
        return ("KEY_UP");
    if (key == KEY_DOWN)
        return ("KEY_DOWN");
    str[0] = (char)key;
    return (str);
}

void print_vars(s_var *all)
{
    my_printf("Key left: %s (%d)\n", return_key(all->key_left),
     all->key_left);
    my_printf("Key right: %s (%d)\n", return_key(all->key_right),
     all->key_right);
    my_printf("Key turn: %s (%d)\n", return_key(all->key_turn_right),
     all->key_turn_right);
    my_printf("Key drop: %s (%d)\n", return_key(all->key_drop),
     all->key_drop);
    my_printf("Key quit: %s (%d)\n", return_key(all->key_quit),
     all->key_quit);
    my_printf("Key pause: %s (%d)\n", return_key(all->key_pause),
     all->key_pause);
    if (all->hide_next == FALSE)
        my_printf("Next: Yes\n");
    else
        my_printf("Next: No\n");
    my_printf("Level: %d\n", all->level);
    my_printf("Size: %d*%d\n\n", all->map_x, all->map_y);
}

void print_tetrimino2(s_var *all, char *filename, char *file_name)
{
    char *text = save_text(filename);
    char **raw = split_string(text, '\n');
    char **matrix = NULL;
    int *info = malloc(sizeof(int) * 3);

    if (raw == NULL || check_tetrimino(raw) == 1) {
        my_printf("Tetrimino '%s': error\n", file_name);
        return;
    }
    info[0] = raw[0][0] - 48;
    info[1] = raw[0][2] - 48;
    info[2] = raw[0][4] - 48;
    matrix = delete_first_line(raw);
    if (check_size(matrix, info[0], info[1]) == 1) {
        my_printf("Tetrimino '%s': error\n", file_name);
        return;
    }
    my_printf("Tetriminos '%s': size %d*%d, color: %d\n", file_name, 
    info[0], info[1], info[2]);
    print_array_strings(matrix);
}

int print_tetrimino(s_var *all)
{
    DIR *d;
    struct dirent *dir;
    char *full_path = "";

    print_vars(all);
    my_printf("Number of tetriminos: %d\n", all->good_pieces_nbr);
    d = opendir("./tetriminos");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (string_contain(dir->d_name, ".tetrimino") == 1) {
                full_path = my_strcat("./tetriminos/", dir->d_name);
                print_tetrimino2(all, full_path, dir->d_name);
            }
        }
        closedir(d);
    }
    return (0);
}
