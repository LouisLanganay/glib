/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_draw_sprites
*/

#include "../gl.h"

void gl_draw_sprites(window_s *window, sprite_t *sprites)
{
    sprite_t *tmp = sprites;
    while (tmp != NULL) {
        sfRenderWindow_drawSprite(window->window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}
