/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** my putchar
*/

#include "./../includes/bsprintf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
