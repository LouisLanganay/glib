/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_event_create
*/

#include "../gl.h"

void gl_create_event(
    int id,
    sfEventType type,
    void (*event)(window_s *window),
    events_l **events
)
{
    events_l *tmp = malloc(sizeof(*tmp));

    tmp->id = id;
    tmp->type = type;
    tmp->event = event;

    tmp->next = *events;
    *events = tmp;
}
