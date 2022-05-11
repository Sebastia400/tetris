/*
** EPITECH PROJECT, 2021
** my revstr
** File description:
** function that reverses a string
*/

int my_strlen2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    i--;
    return (i);
}

char *my_revstr(char *str)
{
    int i = 0;
    int n = my_strlen2(str);
    char temp[n];

    while (str[i] != '\0') {
        temp[n] = str[i];
        i++;
        n--;
    }
    while (n != i) {
        str[n] = temp[n];
        n++;
    }
    return (str);
}
