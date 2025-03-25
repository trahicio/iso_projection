/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** .
*/

#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Vector3.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Mouse.h>
#include <stdio.h>
#include "../include/my.h"

static float absolute(float nb)
{
    if (nb < 0) {
        nb *= -1;
        return nb;
    }
    return nb;
}

static int my_z(int value)
{
    if (value > 6) {
        value = 6;
        return value;
    }
    if (value < -1) {
        value = 5;
        return value;
    }
    return value;
}

static sfVector3f **is_change_pos(sfVector3f **points, world_t *world,
    button_t **button, sfEvent *event)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(world->window);
    int value = button[1]->state + button[2]->state;
    int distance = 50;

    if (value != 0)
        value /= 2;
    for (int u = 0; u != world->size * world->size; u++) {
        if (absolute(pos.x - points[u / world->size]
            [u % world->size].x) <= distance
            && absolute(pos.y - points[u / world->size]
            [u % world->size].y) <= distance) {
            points[u / world->size][u % world->size].y -=
                (points[u / world->size][u % world->size].z * (150 * 0.7) / 3);
            points[u / world->size][u % world->size].z += value;
            points[u / world->size][u % world->size].y +=
                (points[u / world->size][u % world->size].z * (150 * 0.7) / 3);
            return points;
        }
    }
    return NULL;
}

sfVector3f **change_pos(sfVector3f **points, world_t *world,
    button_t **button, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed)
        return is_change_pos(points, world, button, event);
    return NULL;
}
