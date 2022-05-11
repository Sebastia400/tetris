/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "library.h"

int quantity_sentences(int size_text, char *str, char delimiter)
{
    int i = 1;
    int num_sentences = 1;

    while (i < size_text) {
        if (str[i] == delimiter || str[i] == '\0')
            num_sentences++;
        i++;
    } return (num_sentences);
}

int len_sentence(char *arraytext, char delimiter)
{
    int i = 0;
    while (arraytext[i] != '\0' && arraytext[i] != delimiter)
        i++;
    return (i);
}

char **split_string(char *arraytext, char separator)
{
    int len = 0;
    int i = 0;
    int k = 0;
    int j = 0;
    char **sentences;

    sentences = my_calloc(quantity_sentences(my_strlen(arraytext),
    arraytext, '\n') * 2, sizeof(char *));
    while (i < my_strlen(arraytext)) {
        len = len_sentence(arraytext, separator);
        sentences[j] = my_calloc(len * 2 + 10, sizeof(char));
        sentences[j] = my_memset(sentences[j], '\0', len * 2 + 10);
        k = 0;
        while (arraytext[i] != separator && arraytext[i] != '\0' &&
        arraytext[i] != '\n')
            sentences[j][k++] = arraytext[i++];
        j++;
        i++;
    }
    sentences[j] = NULL;
    return (sentences);
}

int get_arguments_ext(s_var *all, int ac, char **av, int i)
{
    if (my_strcmp(av[i], "--help") == 0) {
        print_help();
        return (ac);
    }
    if (i < ac && (my_strcmp(av[i], "-w") == 0 || my_strcmp(av[i],
        "--without-next") == 0)) {
        all->hide_next = TRUE;
        return (i + 1);
    }
    if (i < ac && (my_strcmp(av[i], "-D") == 0 || my_strcmp(av[i],
        "--debug") == 0)) {
        all->show_debug = TRUE;
        return (i + 1);
    }
    return (i);
}

int get_arguments(s_var *all, int ac, char **av)
{
    int i = 1;

    while (i < ac) {
        i = get_arguments_ext(all, ac, av, i);
        i = param_level(all, ac, av, i);
        i = param_left_key(all, ac, av, i);
        i = param_right_key(all, ac, av, i);
        i = param_turn_key(all, ac, av, i);
        i = param_drop_key(all, ac, av, i);
        i = param_quit_key(all, ac, av, i);
        i = param_pause_key(all, ac, av, i);
        i = param_map_size(all, ac, av, i);
        i++;
    }
    return (0);
}
