/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_create_button
*/

#include "../gl.h"

static int gl_create_button_check_id(buttons_l *buttons, int id)
{
    buttons_l *tmp = buttons;
    while (tmp != NULL) {
        if (tmp->id == id)
            return write(2, "(gl_create_button) Button id already exist\n", 43);
        tmp = tmp->next;
    }
    return (0);
}

void gl_create_button(buttons_l **buttons, buttons_l *button)
{
    if (gl_create_button_check_id(*buttons, button->id) != 0)
        exit (84);
    buttons_l *tmp = malloc(sizeof(*tmp));


    tmp->id = button->id;
    tmp->pos = button->pos;
    tmp->sprite = button->sprite;
    tmp->texture = button->texture;
    tmp->rect = button->rect;
    tmp->call_action = button->call_action;

    if (tmp->s_hover != NULL)
        tmp->s_hover = button->s_hover;
    else
        tmp->s_hover = NULL;

    sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
    sfSprite_setTextureRect(tmp->sprite, tmp->rect);
    sfSprite_setPosition(tmp->sprite, tmp->pos);

    tmp->next = *buttons;
    *buttons = tmp;
    free(button);
}