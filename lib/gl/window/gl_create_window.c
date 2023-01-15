/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_init_window
*/

#include "../gl.h"

static int handle_error(int width, int height, char *title, int framerate)
{
    if (width <= 0 || height <= 0)
        return write(2, "(gl_init_window) width or height is invalid\n", 44);
    if (framerate <= 0)
        return write(2, "(gl_init_window) framerate is invalid\n", 38);
    if (width > 1920 || height > 1080)
        return write(2, "(gl_init_window) width or height is too big\n", 44);
    return 0;
}

window_s *gl_create_window(int width, int height, char *title, int framerate)
{
    if (handle_error(width, height, title, framerate) != 0)
        exit(84);

    window_s *window = malloc(sizeof(window_s));

    window->mode = (sfVideoMode){width, height, 32};
    window->window = sfRenderWindow_create(window->mode,
        title, sfTitlebar | sfClose, 0);
    window->clock = sfClock_create();
    window->event;

    if (!window->window)
        exit(84);

    sfRenderWindow_setFramerateLimit(window->window, framerate);
    return (window);
}
