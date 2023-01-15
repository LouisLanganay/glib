/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_check_events
*/

#include "../gl.h"

static int handle_errors(window_t *window, events_t *events)
{
    if (!window || !events)
        write(2, "(gl_check_events) window or events is NULL\n", 43);
    return (0);
}

void gl_check_events(window_t *window, events_t *events)
{
    if (handle_errors(window, events) != 0)
        exit(84);
    events_t *tmp = events;
    sfRenderWindow_pollEvent(window->window, &window->event);
    while (tmp) {
        if (window->event.type == tmp->type)
            tmp->event(window);
        tmp = tmp->next;
    }
}
