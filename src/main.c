/*
** EPITECH PROJECT, 2023
** glib
** File description:
** main
*/

#include "main.h"
#include "gl.h"

void event_window_close(window_s *window)
{
    sfRenderWindow_close(window->window);
}

int main(void)
{
    rpg_s *rpg = malloc(sizeof(rpg_s));
    rpg->window = gl_create_window(800, 600, "My window", 60);
    rpg->events = NULL;
    gl_create_event(544, sfEvtClosed, event_window_close, &rpg->events);
    gl_create_event(888, sfEvtKeyPressed, event_window_close, &rpg->events);


    while (sfRenderWindow_isOpen(rpg->window->window)) {
        gl_check_events(rpg->window, rpg->events);
        sfClock_restart(rpg->window->clock);
    }
}
