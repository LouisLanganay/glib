/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_check_events
*/

#include "../gl.h"

void gl_check_events_list(window_s *window, events_l *events)
{
    events_l *tmp = events;
    sfRenderWindow_pollEvent(window->window, &window->event);
    while (tmp) {
        if (window->event.type == tmp->type)
            tmp->event(window);
        tmp = tmp->next;
    }
}
