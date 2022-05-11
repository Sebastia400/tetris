/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** my putchar
*/

#include "./../includes/bsprintf.h"

void print_type_ce(long units, double value, int elevatmenys, int i)
{
    int n = 0;
    int result = 0;

    value -= units;
    while (n++ != 6) {
        value *= 10;
        result += ((int)value % 10);
        result *= 10;
    }
    result /= 10;
    if (((int)value % 10) != 0)
        result += 1;
    my_printf("%d%c%d%c", units, '.', result, 'E');
    if (elevatmenys)
        my_putchar('-');
    else
        my_putchar('+');
    if (i <= 9)
        my_putchar('0');
    my_put_nbr(i);
}

double extra_ce(double value)
{
    if (value < 0) {
        my_putchar('-');
        value *= -1;
    }
    return (value);
}

void function_ce(va_list list)
{
    int i = 0;
    double value = va_arg(list, double);
    long unidades = 0;
    int elevatmenys = 0;

    unidades = (long)extra_ce(value);
    if (unidades < 1) {
        while (unidades <= 0) {
            value *= 10;
            unidades = (long)value;
            elevatmenys = 1;
            i++;
        }
    } else {
        while (unidades < 1 || unidades > 9) {
            value /= 10;
            unidades = (long)value;
            i++;
        }
    }
    print_type_ce(unidades, value, elevatmenys, i);
}

void print_type_f (long units, float value, int i)
{
    int n = 0;

    value -= units;
    my_put_nbr(units);
    my_putchar('.');
    while (n != 6) {
        value *= 10;
        my_put_nbr((int)value % 10);
        n++;
    }
}

void function_f(va_list list)
{
    double value = va_arg(list, double);
    int i = 0;
    long units = 0;

    if (value < 0) {
        my_putchar('-');
        value *= -1;
    }
    units = value;
    print_type_f(units, value, i);
}
