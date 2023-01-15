/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_draw_texts
*/

#include "../gl.h"

void gl_draw_texts(window_t *window, text_t *texts)
{
    text_t *tmp = texts;
    while (tmp != NULL) {
        sfRenderWindow_drawText(window->window, tmp->text, NULL);
        tmp = tmp->next;
    }
}
