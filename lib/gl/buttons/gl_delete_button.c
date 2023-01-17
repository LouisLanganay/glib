/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_delete_button
*/

#include "../gl.h"

void gl_delete_button(GLib_t *glib, int id)
{
    buttons_t *tmp = glib->buttons;
    buttons_t *prev = NULL;
    while (tmp) {
        if (tmp->id == id) {
            if (prev == NULL)
                glib->buttons = tmp->next;
            else
                prev->next = tmp->next;
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}
