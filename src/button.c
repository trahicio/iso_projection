/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** .
*/

#include "../include/my.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

sfVertexArray **display_button(world_t *window, button_t **button,
    sfVertexArray **is_old)
{
    for (int i = 0; button[i] != NULL; i++) {
        sfSprite_setTexture(button[i]->sprite, button[i]->texture, sfTrue);
        sfRenderWindow_drawSprite(window->window, button[i]->sprite, NULL);
    }
    return NULL;
}

static sfTexture *set_button_size(sfTexture *texture, sfSprite *sprite,
    int x, int y)
{
    sfVector2f scale;
    sfVector2u texture_size = sfTexture_getSize(texture);

    scale.x = (float)x / texture_size.x;
    scale.y = (float)y / texture_size.y;
    sfSprite_setScale(sprite, scale);
    return texture;
}

static void set_button_position(button_t **button, world_t *world, int nb)
{
    sfVector2f pos;
    int j = 0;

    for (int i = 0; i < nb - 1; i++) {
        pos.x = 50 + j * 100;
        pos.y = 50;
        sfSprite_setPosition(button[i]->sprite, pos);
        j++;
    }
}

static void set_texture_button(button_t *button, int j)
{
    char filename[100];
    char filename_mouse[100];
    char filename_on[100];

    snprintf(filename, sizeof(filename), "asset/button%i.png", j);
    snprintf(filename_mouse, sizeof(filename_mouse),
        "asset/button%i_mouse.png", j);
    snprintf(filename_on, sizeof(filename_on), "asset/button%i_on.png", j);
    button->sprite = sfSprite_create();
    button->texture_hidle = sfTexture_createFromFile(filename, NULL);
    button->texture = button->texture_hidle;
    button->texture_mouse = sfTexture_createFromFile(filename_mouse, NULL);
    button->texture_on = sfTexture_createFromFile(filename_on, NULL);
    button->texture = set_button_size(button->texture,
        button->sprite, 85, 85);
    button->texture_mouse = set_button_size(button->texture_mouse,
        button->sprite, 85, 85);
    button->texture_on = set_button_size(button->texture_on,
        button->sprite, 85, 85);
}

static void set_exit_button(button_t *button, world_t *world)
{
    sfVector2f pos;
    sfVector2u window_size = sfRenderWindow_getSize(world->window);

    pos.x = window_size.x - 175;
    pos.y = 50;
    button->sprite = sfSprite_create();
    button->texture_hidle = sfTexture_createFromFile("asset/button5.png",
        NULL);
    button->texture = button->texture_hidle;
    button->texture_mouse = sfTexture_createFromFile("asset/button5_mouse.png",
        NULL);
    button->texture_on = sfTexture_createFromFile("asset/button5_on.png",
        NULL);
    button->texture = set_button_size(button->texture,
        button->sprite, 135, 85);
    sfSprite_setPosition(button->sprite, pos);
}

button_t **init_button(int nb, world_t *world)
{
    button_t **button = malloc(sizeof(button_t *) * (nb + 1));
    int j = 1;

    if (button == NULL)
        return NULL;
    for (int i = 0; i < nb; i++) {
        button[i] = malloc(sizeof(button_t));
        if (button[i] == NULL)
            return NULL;
        if (j == 5) {
            set_exit_button(button[i], world);
            break;
        }
        set_texture_button(button[i], j);
        j++;
    }
    button[nb] = NULL;
    set_button_position(button, world, nb);
    return button;
}
