/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_init_window
*/

#include "../gl.h"

window_s *gl_init_window(int width, int height, char *title)
{
    window_s *window = malloc(sizeof(window_s));
    window->mode = (sfVideoMode){width, height, 32};
    window->window = sfRenderWindow_create(window->mode,
        title, sfTitlebar | sfClose, 0);
    window->clock = sfClock_create();
    window->event;
    return (window);
}
