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
    #include <unistd.h>


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
     * @brief events_l struct for event management
     */
    typedef struct events_l {
        int id;
        sfEventType type;
        void (*event)(window_s *window);
        struct events_l *next;
    } events_l;

    /**
     * @brief create window
     * @param width Width of the window
     * @param height Height of the window
     * @param title Title of the window
     * @param framerate Framerate of the window
     * @return window_s* Return a window_s struct
     */
    window_s *gl_create_window(int width, int height, char *title, int framerate);

    /**
     * @brief create event
     * @param type Event type (sfEvtClosed, sfEvtKeyPressed, ...)
     * @param id Event id
     * @param event Event function
     * @param events List of events
     * @return events_l* Return a events_l struct
     */
    void gl_create_event(
        int id,
        sfEventType type,
        void (*event)(window_s *window),
        events_l **events
    );

    /**
     * @brief check events
     * @param window Window struct
     * @param events List of events
     */
    void gl_check_events(window_s *window, events_l *events);

#endif
