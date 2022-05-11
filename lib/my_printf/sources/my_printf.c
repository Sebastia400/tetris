/*
** EPITECH PROJECT, 2021
** B-PSU-100-BAR-1-1-bsmyprintf-sebastia.gomez-dolc
** File description:
** disp_stdarg.c
*/

#include "./../includes/bsprintf.h"

void my_printf(char *s, ...)
{
    int i = 0;

    va_list list;
    va_start(list, s);
    while (s[i] != '\0') {
        if (s[i] == '%') {
            i++;
            while (s[i] != '\0' && !isalpha(s[i]) && s[i] != '%') {
                i++;
            }
            do_op(list, s[i]);
        } else
            my_putchar(s[i]);
        i++;
    }
    va_end(list);
}
