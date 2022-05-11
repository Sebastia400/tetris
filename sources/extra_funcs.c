/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

void select_color1(char character)
{
    if (character > '0' && character <= '9')
        attron(COLOR_PAIR(character - 48));
    else {
        switch (character) {
            case '*':
                attron(COLOR_PAIR(10));
                break;
            case ' ':
                attron(COLOR_PAIR(11));
                break;
            default:
                attron(COLOR_PAIR(2));
                break;
        }
    }
}

void print_help(void)
{
    my_printf("Usage: ./tetris [options]\n");
    my_printf("Options:\n");
    my_printf("  --help              Display this help\n");
    my_printf("-L --level={num}      Start Tetris at level num (def: 1)\n");
    my_printf("-l --key-left={K}     Move the tetrimino LEFT using the K key\
     (def: left arrow)\n");
    my_printf("-r --key-right={K}    Move the tetrimino RIGHT using the K key\
     (def: right arrow)\n");
    my_printf("-t --key-turn={K]     TURN the tetrimino clockwise 90d using th\
    e K key (def: top arrow)\n");
    my_printf("-d --key-drop={K}     DROP the tetrimino using the K key (def:\
     down arrow)\n");
    my_printf("-q --key-quit={K}     QUIT the game using the K key (def: 'q' \
    key)\n");
    my_printf("-P --key-pause={(K}   PAUSE/RESTART the game using the K key \
    (def: space bar)\n");
    my_printf("--map-size=(row,col)  Set the numbers of rows and columns of \
    the map (def: 20,10)\n");
    my_printf("-w --without-next     Hide next tetrimino (def: false)\n");
    my_printf("-D --debug            Debug mode (def: false)\n");
}

int check_size_ext(char **matrix, int i, int j, int n)
{
    if (matrix[i][j] == '*') {
        n++;
    }
    return (n);
}

int check_size(char **matrix, int width, int height)
{
    int i = 0;
    int j = 0;
    int max_width = -1;
    int n = 0;

    for (j = 0; matrix[i] != NULL; i++) {
        while (matrix[i][j] != '\0') {
            n = check_size_ext(matrix, i, j, n);
            j++;
        }
        if (j > max_width)
            max_width = j;
        n = 0;
    }
    if (i != height)
        return (1);
    if (max_width!= width)
        return (1);
    return (0);
}

int check_tetrimino(char **matrix)
{
    if (my_strlen(matrix[0]) != 5)
        return (1);
    if (c_is_num(matrix[0][0]) != 1 || c_is_num(matrix[0][2]) != 1
    || c_is_num(matrix[0][4]) != 1)
        return (1);
    if (check_valid_char(matrix) == 1)
        return (1);
    return (0);
}
