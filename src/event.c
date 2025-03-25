/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** .
*/

#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector3.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

static void my_exit(world_t *my_window, button_t **buttons, sfEvent *event)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(my_window->window);
    sfFloatRect check_pos_kirby = sfSprite_getGlobalBounds(buttons[4]->sprite);

    if (sfFloatRect_contains(&check_pos_kirby, position.x, position.y)) {
        buttons[4]->texture = buttons[4]->texture_mouse;
        if (event->type == sfEvtMouseButtonPressed) {
            buttons[4]->texture = buttons[4]->texture_on;
            sfRenderWindow_close(my_window->window);
        }
    } else
        buttons[4]->texture = buttons[4]->texture_hidle;
}

static void my_down(world_t *my_window, button_t **buttons, sfEvent *event)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(my_window->window);
    sfFloatRect check_pos_kirby = sfSprite_getGlobalBounds(buttons[2]->sprite);
    static int i = 1;

    if (sfFloatRect_contains(&check_pos_kirby, position.x, position.y)) {
        buttons[2]->texture = buttons[2]->texture_mouse;
        if (event->type == sfEvtMouseButtonPressed)
            i *= -1;
    } else {
        buttons[2]->texture = buttons[2]->texture_hidle;
        if (i == -1)
            buttons[2]->texture = buttons[2]->texture_on;
        if (i == 1)
            buttons[2]->texture = buttons[2]->texture_hidle;
    }
    buttons[2]->state = i;
}

static void my_up(world_t *my_window, button_t **buttons, sfEvent *event)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(my_window->window);
    sfFloatRect check_pos_kirby = sfSprite_getGlobalBounds(buttons[1]->sprite);
    static int i = -1;

    if (sfFloatRect_contains(&check_pos_kirby, position.x, position.y)) {
        buttons[1]->texture = buttons[1]->texture_mouse;
        if (event->type == sfEvtMouseButtonPressed)
            i *= -1;
    } else {
        buttons[1]->texture = buttons[1]->texture_hidle;
        if (i == 1)
            buttons[1]->texture = buttons[1]->texture_on;
        if (i == -1)
            buttons[1]->texture = buttons[1]->texture_hidle;
    }
    buttons[1]->state = i;
}

static int **my_set_int(int size)
{
    int **array = NULL;

    if (!size || size <= 0)
        size = 8;
    array = malloc(sizeof(int *) * (size + 1));
    for (int i = 0; i != size; i++) {
        array[i] = malloc(sizeof(int) * (size + 1));
        for (int u = 0; u != size; u++)
            array[i][u] = 0;
    }
    return array;
}

sfVector3f **is_update(sfVertexArray **is_old, world_t *my_window,
    button_t **button, sfEvent *event)
{
    sfVector3f **is_new = NULL;

    is_new = my_restart(my_window, button, event);
    if (!is_new)
        is_new = my_shuffle(my_window, button, event);
    if (is_new) {
        destroy(my_window->window, is_old, my_window->size);
        return is_new;
    }
    return NULL;
}

sfVector3f **check_event(sfVertexArray **is_old, world_t *my_window,
    button_t **button, sfVector3f **points)
{
    sfEvent event;
    sfVector3f **array = NULL;

    while (sfRenderWindow_pollEvent(my_window->window, &event)) {
        if (sfEvtKeyPressed == event.type && event.key.code == sfKeyQ)
            sfRenderWindow_close(my_window->window);
        my_up(my_window, button, &event);
        my_down(my_window, button, &event);
        my_exit(my_window, button, &event);
        if (!array)
            array = is_update(is_old, my_window, button, &event);
        if (!array && (button[1]->state + button[2]->state) != 0)
            array = change_pos(points, my_window, button, &event);
        if (array)
            return array;
        return NULL;
    }
    return NULL;
}
