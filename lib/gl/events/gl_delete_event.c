/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_delete_event
*/

#include "../gl.h"

void gl_delete_event(GLib_t *glib, int id)
{
    events_t *tmp = glib->sprites;
    events_t *prev = NULL;
    while (tmp) {
        if (tmp->id == id) {
            if (prev == NULL)
                glib->sprites = tmp->next;
            else
                prev->next = tmp->next;
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}
