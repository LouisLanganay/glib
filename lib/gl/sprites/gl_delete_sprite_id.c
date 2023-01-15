/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_delete_sprite
*/

#include "../gl.h"

void gl_delete_sprite(sprite_t **sprites, int id)
{
    sprite_t *tmp = *sprites;
    sprite_t *prev = NULL;
    while (tmp != NULL) {
        if (tmp->id == id) {
            sfSprite_destroy(tmp->sprite);
            sfTexture_destroy(tmp->texture);
            if (prev == NULL)
                *sprites = tmp->next;
            else
                prev->next = tmp->next;
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}
