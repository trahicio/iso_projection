/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** .
*/

#include <fcntl.h>
#include <stddef.h>
#include "../include/my.h"


void destroy(sfRenderWindow *window, sfVertexArray **lines, int size)
{
    for (int i = 0; i != size * size && lines[i]; i++)
        sfVertexArray_destroy(lines[i]);
}
