/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_event_create
*/

#include "../gl.h"

static int gl_create_event_check_id(events_l *events, int id)
{
    events_l *tmp = events;
    while (tmp != NULL) {
        if (tmp->id == id)
            return write(2, "(gl_create_event) Event id already exist\n", 41);
        tmp = tmp->next;
    }
    return (0);
}

void gl_create_event(
    int id,
    sfEventType type,
    void (*event)(window_s *window),
    events_l **events
)
{
    if (gl_create_event_check_id(*events, id) != 0)
        exit (84);

    events_l *tmp = malloc(sizeof(*tmp));
    if (tmp == NULL)
        return write(2, "(gl_create_event) Malloc failed\n", 32);

    tmp->id = id;
    tmp->type = type;
    tmp->event = event;

    tmp->next = *events;
    *events = tmp;
}
