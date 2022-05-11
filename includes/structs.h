/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** fgfghgf
*/

#ifndef STRUCTS_H_
    #define STRUCTS_H_
    #include <time.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>

    typedef struct s_info_parts {
        char ***orient_part;
        int x;
        int y;
        int color;
        int num_part;
        struct s_info_parts *next_part;
    } t_info_parts;

    typedef struct t_var {
        int level;
        int key_left;
        int key_right;
        int key_turn_left;
        int key_turn_right;
        int key_drop;
        int key_quit;
        int key_pause;
        int key_restart;
        int map_x;
        int map_y;
        bool hide_next;
        bool show_debug;
        bool pause;
        int return_value;
        int score;
        int max_score;
        int x_pos;
        int y_pos;
        int rotation;
        int pieces_nbr;
        int good_pieces_nbr;
        char **map;
        char **temp_map;
        char **map_score;
        char **map_nextpart;
        double total_time;
        double initial_time;
        struct s_info_parts *current_part;
        struct s_info_parts *next_part;
        struct s_info_parts *all_parts;
    } s_var;

    typedef struct strucrt_pages_t {
        int op;
        void (*ptr)(s_var *all);
    } struct_pages;

#endif
