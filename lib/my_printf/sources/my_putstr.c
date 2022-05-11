/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** a function that displays, one-by-one, the characters of a string
*/

#include "./../includes/bsprintf.h"

int my_putstr(char *str)
{
    int  n = 0;

    while (str[n] != '\0') {
        my_putchar(str[n]);
        n++;
    }
    return (0);
}
