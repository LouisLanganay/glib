/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_draw_sprite_id
*/

#include "../gl.h"

void gl_draw_sprite(window_t *window, sprite_t *sprites, int id)
{
    sprite_t *tmp = sprites;
    while (tmp != NULL) {
        if (tmp->id == id) {
            sfRenderWindow_drawSprite(window->window, tmp->sprite, NULL);
            return;
        }
        tmp = tmp->next;
    }
}
