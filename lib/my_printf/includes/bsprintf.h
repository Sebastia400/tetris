/*
** EPITECH PROJECT, 2021
** Sebas-i-victor-printf
** File description:
** bsprintf.h
*/

#ifndef BSPRINTF_H_
    #define BSPRINTF_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <string.h>
    #include <ctype.h>
    #include <stdlib.h>

long my_put_nbr(long nb);
void my_putchar(char c);
int my_putstr(char *str);
char *my_revstr (char *str);
int sum_numbers(int n, ...);
int sum_strings_length(int n, ...);
void my_printf(char *s, ...);
void print_type_e (long unidades, double value, int elevatmenys, int i);
void print_type_ce (long unidades, double value, int elevatmenys, int i);
int do_op(va_list list, char type);
void function_ce(va_list value);
void function_f(va_list list);
void function_g(va_list list);
void function_cg(va_list list);
void function_x(va_list list);
void function_s(va_list list);
void function_c(va_list list);
void function_i_d(va_list list);
void function_cx(va_list list);
void function_u(va_list list);
void function_o(va_list list);
void function_e(va_list list);
void function_p(va_list list);
void function_cs(va_list list);
void function_cb(va_list list);
void function_module(va_list list);
void none();
void printelements(int num, int x, int y);

    typedef struct do_op
    {
        char op;
        void (*ptr)(va_list list);
    } calculator;

#endif
