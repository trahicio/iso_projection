/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** .
*/

#include <SFML/Graphics/Color.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/my.h"

sfColor my_color(float z)
{
    sfColor color = sfWhite;

    z += 1;
    if (z <= 0 && z > -1)
        color = sfColor_fromRGB(255, 143, 0);
    if (z <= 1 && z > 0)
        color = sfRed;
    if (z <= 2 && z > 1)
        color = sfYellow;
    if (z <= 3 && z > 2)
        color = sfGreen;
    if (z <= 4 && z > 3)
        color = sfBlue;
    if (z <= 5 && z > 4)
        color = sfMagenta;
    return color;
}

void my_print(sfRenderWindow *window, sfVertexArray **lines, int size)
{
    for (int i = 0; i != size*(size) && lines[i]; i++)
        sfRenderWindow_drawVertexArray(window, lines[i], NULL);
    return;
}
