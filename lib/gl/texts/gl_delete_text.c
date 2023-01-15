/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_delete_text
*/

#include "../gl.h"

void gl_delete_text(text_t **texts, int id)
{
    text_t *tmp = *texts;
    text_t *prev = NULL;
    while (tmp != NULL) {
        if (tmp->id == id) {
            if (prev == NULL)
                *texts = tmp->next;
            else
                prev->next = tmp->next;
            sfText_destroy(tmp->text);
            sfFont_destroy(tmp->font);
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}
