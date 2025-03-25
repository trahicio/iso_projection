/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** .
*/

#include <SFML/Graphics/Types.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>

#ifndef MY_WORLD_H
    #define MY_WORLD_H

typedef struct world_s {
    sfRenderWindow *window;
    sfTexture *texture_bg;
    sfSprite *background;
    int size;
} world_t;

typedef struct button_s {
    sfTexture *texture;
    sfTexture *texture_hidle;
    sfTexture *texture_mouse;
    sfTexture *texture_on;
    sfSprite *sprite;
    int state;
} button_t;

button_t **init_button(int nb, world_t *world);
sfVertexArray **display_button(world_t *window, button_t **button,
    sfVertexArray **is_old);
#endif
