/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** lib my_hunterexercise
*/

#ifndef LIBRAY_H_
    #define LIBRAY_H_
    #include <string.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stddef.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <ctype.h>
    #include "./structs.h"
    #include <math.h>
    #include <ncurses.h>
    #include <dirent.h>
    #include <stdio.h>
    #include "bsprintf.h"

void *my_memset(void *s, int c, int n);
int my_strlen(char *str);
int my_strcmp(char *s1, char *s2);
int my_getnbr(char *str);
int is_char_in_str(int n, char *str);
char **split_string(char *str, char c);
int is_number(char *str);
int get_arguments(s_var *all, int ac, char **av);
int check_tetrimino(char **matrix);
int tetriminos_nbr(s_var *all);
char *my_strdup(char *str);
char *my_revstr(char *str);
int matrix_len(char **matrix);
char **save_matrix(char **matrix);
void manage_keys(s_var *all, int key_pressed);
char *my_return_char(int nb);
char *save_text(char *filepath);
int matcmp(char **matrix_1, char **matrix_2);
void delete_n_line(s_var *all, int n);
int string_contain(char *str, char *to_find);
int check_size(char **matrix, int width, int height);
int check_tetrimino(char **matrix);
char **delete_first_line(char **array);
int print_tetrimino(s_var *all);
void print_vars(s_var *all);
int my_nbrlen(int nb);
int c_is_num(char c);
int check_valid_char(char **matrix);
void init_window(void);
s_var *init_struct();
void init_colors(void);
void print_help(void);
void display_pause(s_var *all);
void manage_display(s_var *all);
void display_map(char **map, int x, int y);
void print_text(char *map, int x, int y);
void print_num(int num, int x, int y);
void select_color1(char character);
void display_screen(s_var *all);
char **orient_part_90(char **matrix);
char **orient_part_180(char **matrix);
void restart_game(s_var *all);
void quit_game(s_var *all);
int check_if_lost(s_var *all);
double get_eleapsed_time(double current_time, double first_time);
void pause_on_off(s_var *all);
char **create_map(int x, int y);
t_info_parts *rand_next_part(s_var *all, t_info_parts *parts);
void go_down(s_var *all);
char *my_strcat(char *dest, char *src);
void *my_calloc(int nmemb, int size);
char **maplayout(int x, int y);
int param_level(s_var *all, int argc, char **argv, int i);
int param_left_key(s_var *all, int argc, char **argv, int i);
int param_right_key(s_var *all, int argc, char **argv, int i);
int param_turn_key(s_var *all, int argc, char **argv, int i);
int param_drop_key(s_var *all, int argc, char **argv, int i);
int param_quit_key(s_var *all, int argc, char **argv, int i);
int param_pause_key(s_var *all, int argc, char **argv, int i);
int param_map_size(s_var *all, int argc, char **argv, int i);
void pause_on_off(s_var *all);
void print_array_strings(char **array);
int down_colision(s_var *all);
int right_colision(s_var *all);
int left_colision(s_var *all);
void colide(s_var *all);
void convert_0_to_pice(s_var *all);
void write_current_pice(s_var *all);
void get_new_pice(s_var *all);
void go_down(s_var *all);
void go_right(s_var *all);
void go_left(s_var *all);
void go_rotate_right(s_var *all);
void go_rotate_left(s_var *all);
void drop_part(s_var *all);
t_info_parts *init_struc_parts(void);
t_info_parts *ini_linked_part(char **part, int i, int *info);
void create_part(t_info_parts *parts, char **part, int *info);
int check_if_line_is_full(char **map);
void delete_n_line(s_var *all, int n);
void supres_elements_array(char **array, char c, char d);
void restart_game(s_var *all);
void quit_game(s_var *all);

#endif
