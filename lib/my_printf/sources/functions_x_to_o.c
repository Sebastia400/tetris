/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** my putchar
*/

#include <stdarg.h>
#include "./../includes/bsprintf.h"

void function_X(va_list list)
{
    long decimalnum = va_arg(list, long);
    long quotient, carry;
    int i = 0;
    int j = 0;
    char hexadecimalnum[100];

    if (decimalnum != 0) {
        if (decimalnum < 0)
            decimalnum = 4294967295 + (decimalnum + 1);
        quotient = decimalnum;
        while (quotient != 0) {
            carry = quotient % 16;
            if (carry < 10)
                hexadecimalnum[j++] = 48 + carry;
            else
                hexadecimalnum[j++] = 55 + carry;
            quotient = quotient / 16;
        }
    } else
        hexadecimalnum[0] = '0';
    my_putstr(my_revstr(hexadecimalnum));
}

void function_p(va_list list)
{
    char *val = (char *)va_arg(list, char *);

    size_t int_value = (size_t)val;
    my_putstr("0x");
    my_printf("%x", int_value);
}

void function_o(va_list list)
{
    long decimalnum = va_arg(list, long);
    long quotient;
    long carry;
    int j = 0;
    char hexadecimalnum[100];

    if (decimalnum != 0) {
        if (decimalnum < 0)
            decimalnum = 4294967295 + (decimalnum + 1);
        quotient = decimalnum;
        while (quotient != 0) {
            carry = quotient % 8;
            if (carry < 8)
                hexadecimalnum[j++] = 48 + carry;
            quotient = quotient / 8;
        }
    } else
        hexadecimalnum[0] = '0';
    my_putstr(my_revstr(hexadecimalnum));
}

void function_u(va_list list)
{
    long decimalnum = va_arg(list, long);

    if (decimalnum < 0)
        decimalnum = 4294967295 + (decimalnum + 1);
    my_put_nbr(decimalnum);
}

void function_B(va_list list)
{
    long decimalnum = va_arg(list, long);
    char binarinum[100];
    int i = 0;

    while (decimalnum > 0) {
        binarinum[i] = (decimalnum % 2) + 48;
        decimalnum /= 2;
        i++;
    }
    binarinum[i] = '\0';
    my_putstr(my_revstr(binarinum));
}
