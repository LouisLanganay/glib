/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_delete_texts
*/

#include "../gl.h"

void gl_delete_texts(text_t **texts)
{
    text_t *tmp = *texts;
    text_t *prev = NULL;
    while (tmp != NULL) {
        if (prev == NULL)
            *texts = tmp->next;
        else
            prev->next = tmp->next;
        sfText_destroy(tmp->text);
        sfFont_destroy(tmp->font);
        free(tmp);
        prev = tmp;
        tmp = tmp->next;
    }
}
