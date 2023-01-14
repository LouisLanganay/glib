/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_create_button
*/

#include "../gl.h"

static int gl_create_button_check_id(button_s *buttons, int id)
{
    button_s *tmp = buttons;
    while (tmp != NULL) {
        if (tmp->id == id)
            return write(2, "(gl_create_button) Button id already exist\n", 43);
        tmp = tmp->next;
    }
    return (0);
}

void gl_create_button(button_s **buttons, button_s *button)
{
    if (gl_create_button_check_id(*buttons, button->id) != 0)
        exit(84);
    button_s *tmp = *buttons;
    tmp->id = button->id;
    tmp->pos = button->pos;
    tmp->shape = button->shape;
    tmp->texture = button->texture;
    tmp->call_action = button->call_action;
    
    tmp->next = *buttons;
    *buttons = tmp;
}