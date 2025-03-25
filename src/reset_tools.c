/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** .
*/

#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector3.h>
#include <SFML/Window/Event.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

static int **my_set_int(int size)
{
    int **array = NULL;

    if (!size || size <= 0)
        size = 8;
    array = malloc(sizeof(int *) * (size + 1));
    for (int i = 0; i != size; i++) {
        array[i] = malloc(sizeof(int) * (size + 1));
        for (int u = 0; u != size; u++)
            array[i][u] = 3;
    }
    return array;
}

static sfVector3f **my_reset(int size, sfRenderWindow *window)
{
    int **array = my_set_int(size);

    return creat2dmap(array, size);
}

static sfVector3f **my_reset_shuffle(int size, sfRenderWindow *window)
{
    int **array = set_int(size);

    return creat2dmap(array, size);
}

sfVector3f **my_shuffle(world_t *my_window, button_t **buttons, sfEvent *event)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(my_window->window);
    sfFloatRect check_pos_kirby = sfSprite_getGlobalBounds
    (buttons[3]->sprite);

    if (sfFloatRect_contains(&check_pos_kirby, position.x, position.y)) {
        sfRenderWindow_drawSprite(my_window->window, buttons[3]->sprite,
            NULL);
        buttons[3]->texture = buttons[3]->texture_mouse;
    } else
            buttons[3]->texture = buttons[3]->texture_hidle;
    if (sfFloatRect_contains(&check_pos_kirby, position.x, position.y)
    && event->type == sfEvtMouseButtonPressed) {
        buttons[3]->texture = buttons[3]->texture_on;
        return my_reset_shuffle(my_window->size, my_window->window);
    }
    return NULL;
}

sfVector3f **my_restart(world_t *my_window, button_t **buttons, sfEvent *event)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(my_window->window);
    sfFloatRect check_pos_kirby = sfSprite_getGlobalBounds
    (buttons[0]->sprite);

    if (sfFloatRect_contains(&check_pos_kirby, position.x, position.y)) {
        sfRenderWindow_drawSprite(my_window->window, buttons[0]->sprite,
            NULL);
        buttons[0]->texture = buttons[0]->texture_mouse;
    } else
            buttons[0]->texture = buttons[0]->texture_hidle;
    if (sfFloatRect_contains(&check_pos_kirby, position.x, position.y)
    && event->type == sfEvtMouseButtonPressed) {
        buttons[0]->texture = buttons[0]->texture_on;
        return my_reset(my_window->size, my_window->window);
    }
    return NULL;
}
