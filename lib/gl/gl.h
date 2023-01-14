/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl
*/

#ifndef _GL_H__
    #define _GL_H__

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/Network.h>
    #include <stdlib.h>


    /**
     * @brief window_s struct for window management
     */
    typedef struct window_s {
        sfRenderWindow* window;
        sfVideoMode mode;
        sfClock* clock;
        sfEvent event;
    } window_s;

    /**
     * @brief init window
     * @param width Width of the window
     * @param height Height of the window
     * @param title Title of the window
     * @return window_s* Return a window_s struct
     */
    window_s *gl_init_window(int width, int height, char *title);

#endif
