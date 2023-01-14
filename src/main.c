/*
** EPITECH PROJECT, 2023
** glib
** File description:
** main
*/

#include "main.h"
#include "gl.h"

int main(void)
{

    window_s *window = gl_init_window(800, 600, "My window", 60);
    while (sfRenderWindow_isOpen(window->window)) {
        sfClock_restart(window->clock);
    }
}
