/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_delete_scene
*/

#include "../gl.h"

void gl_delete_scene(GLib_t *glib, int id)
{
    scenes_t *tmp = glib->scenes;
    scenes_t *prev = NULL;
    while (tmp) {
        if (tmp->id == id) {
            if (prev == NULL)
                glib->scenes = tmp->next;
            else
                prev->next = tmp->next;
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}
