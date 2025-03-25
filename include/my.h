/*
** EPITECH PROJECT, 2025
** my_list
** File description:
** ddd
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <math.h>
#include <fcntl.h>
#include <stddef.h>
#include "my_world.h"

#ifndef FUNCTION_H
    #define FUNCTION_H
void destroy(sfRenderWindow *window, sfVertexArray **lines, int size);
sfColor my_color(float z);
void my_print(sfRenderWindow *window, sfVertexArray **lines, int size);
sfVector3f **check_event(sfVertexArray **is_old, world_t *my_window,
    button_t **button, sfVector3f **points);
sfVector3f project_iso_point(int x, int y, int z);
sfVector3f **creat2dmap(int **map3d, int size);
sfVertexArray *create_line(sfVector3f *point1, sfVector3f *point2,
    sfVector3f *point3, sfVector3f *point4);
sfVertexArray **draw_2d_map(sfRenderWindow *window, sfVector3f **map_2d,
    int size, int **array);
int **set_int(int size);
sfVector3f **is_update(sfVertexArray **is_old, world_t *my_window,
    button_t **button, sfEvent *event);
sfVector3f **change_pos(sfVector3f **points, world_t *world,
    button_t **button, sfEvent *event);
sfVector3f **my_shuffle(world_t *my_window,
    button_t **buttons, sfEvent *event);
sfVector3f **my_restart(world_t *my_window,
    button_t **buttons, sfEvent *event);
#endif
