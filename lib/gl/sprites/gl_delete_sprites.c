/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_delete_sprites
*/

#include "../gl.h"

void gl_delete_sprites(sprite_t **sprites)
{
    sprite_t *tmp = *sprites;
    sprite_t *next = NULL;
    while (tmp != NULL) {
        next = tmp->next;
        sfSprite_destroy(tmp->sprite);
        sfTexture_destroy(tmp->texture);
        free(tmp);
        tmp = next;
    }
    *sprites = NULL;
}
