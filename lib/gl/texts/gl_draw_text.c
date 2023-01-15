/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_draw_text
*/

#include "../gl.h"

void gl_draw_text(window_t *window, text_t *texts, int id)
{
    text_t *tmp = texts;
    while (tmp != NULL) {
        if (tmp->id == id) {
            sfRenderWindow_drawText(window->window, tmp->text, NULL);
            return;
        }
        tmp = tmp->next;
    }
}
