/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** .
*/

#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector3.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/my.h"

static void init_struct(world_t *world, int size)
{
    sfVideoMode video_mode = {.width = 1200, .height = 900,
        .bitsPerPixel = 32};
    sfVector2f scale;
    sfVector2u texture_size;

    world->size = size;
    world->window = sfRenderWindow_create(video_mode, "my_world",
        sfClose, NULL);
    sfRenderWindow_setFramerateLimit(world->window, 60);
    world->texture_bg = sfTexture_createFromFile("asset/background.png"
        , NULL);
    world->background = sfSprite_create();
    texture_size = sfTexture_getSize(world->texture_bg);
    scale.x = (float)video_mode.width / texture_size.x;
    scale.y = (float)video_mode.height / texture_size.y;
    sfSprite_setTexture(world->background, world->texture_bg, sfTrue);
    sfSprite_setScale(world->background, scale);
}

static void display_background(world_t *world)
{
    sfRenderWindow_drawSprite(world->window, world->background, NULL);
}

static sfVector3f **what_is_happening(world_t *world, sfVertexArray **lines,
    button_t **button, sfVector3f **points)
{
    sfVector3f **tmp = NULL;

    sfRenderWindow_display(world->window);
    display_background(world);
    tmp = check_event(lines, world, button, points);
    if (tmp) {
    points = tmp;
    }
    return points;
}

int main(int argc, char **argv)
{
    world_t *world = malloc(sizeof(world_t));
    button_t **button;
    int size = 8;
    int **array = set_int(size);
    sfVertexArray **lines;
    sfVector3f **points = creat2dmap(array, size);

    init_struct(world, size);
    button = init_button(5, world);
    lines = draw_2d_map(world->window, points, size, array);
    while (sfRenderWindow_isOpen(world->window)) {
        points = what_is_happening(world, lines, button, points);
        lines = draw_2d_map(world->window, points, world->size, NULL);
        my_print(world->window, lines, world->size);
        display_button(world, button, lines);
    }
    destroy(world->window, lines, size);
    return 0;
}
