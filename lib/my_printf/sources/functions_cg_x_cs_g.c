/*
** EPITECH PROJECT, 2021
** Sebas-i-victor-myprintf
** File description:
** function_4.c
*/

#include "./../includes/bsprintf.h"

void function_cg(va_list list)
{
    double value = va_arg(list, double);

    if (value < 0.0001 || value > 100000)
        my_printf("%E", value);
    else
        my_printf("%f", value);
}

void function_x(va_list list)
{
    long decimalnum = va_arg(list, long);
    long quotient = decimalnum;
    long carry;
    int j = 0;
    char hexadecimalnum[100];

    if (decimalnum != 0) {
        if (decimalnum < 0)
            decimalnum = 4294967295 + (decimalnum + 1);
        while (quotient != 0) {
            carry = quotient % 16;
            if (carry < 10)
                hexadecimalnum[j++] = 48 + carry;
            else
                hexadecimalnum[j++] = 87 + carry;
            quotient = quotient / 16;
        }
    } else
        hexadecimalnum[0] = '0';
    my_putstr(my_revstr(hexadecimalnum));
}

void function_cs(va_list list)
{
    char *str = (char *)va_arg(list, char *);
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] < 32 || str[i] > 127) {
            my_putchar(92);
            my_printf("%o", str[i]);
        } else
            my_printf("%c", str[i]);
        i++;
    }
}

void function_g(va_list list)
{
    double value = va_arg(list, double);

    if (value < 0.0001 || value > 100000)
        my_printf("%e", value);
    else
        my_printf("%f", value);

}

void function_module(va_list list)
{
    double value = va_arg(list, double);
    my_putchar('%');
}
