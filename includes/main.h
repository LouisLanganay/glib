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

    #include "gl.h"

    typedef struct rpg_s {
        window_s *window;
        events_l *events;
        sprite_t *sprites;
        text_t *texts;
        
    } rpg_s;
#endif
