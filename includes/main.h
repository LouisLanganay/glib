/*
** EPITECH PROJECT, 2023
** glib
** File description:
** main
*/

#ifndef _MAIN_H__
    #define _MAIN_H__

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/Network.h>

    typedef struct csfml_s {
        sfRenderWindow* window;
        sfVideoMode mode;
        sfClock* clock;
        sfEvent event;
    } csfml_s;


#endif
