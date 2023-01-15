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
     * @brief buttons_l struct for button management
     */
    typedef struct buttons_l {
        int id;
        sfBool hovered;
        sfBool disabled;
        sfVector2f pos;
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect rect;
        sfSound *ss_hover;
        sfSoundBuffer *sb_hover;
        sfSound *ss_click;
        sfSoundBuffer *sb_click;
        void (*call_action)(int id);
        struct buttons_l *next;
    } buttons_l;






    /**
     * @brief create window
     * @param width Width of the window
     * @param height Height of the window
     * @param title Title of the window
     * @param framerate Framerate of the window
     * @return window_s* Return a window_s struct
     */
    window_s *gl_create_window(
        int width,
        int height,
        char *title,
        int framerate
    );

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

    /**
     * @brief Create a button object
     * @param buttons Buttons list
     * @param button Button struct
     * @return int Return 0 if success, 84 if error
     */
    int gl_create_button(buttons_l **buttons, buttons_l *button);

    /**
     * @brief Create a button object
     * @param id Button id
     * @param buttons Buttons list
     * @param window Window struct
     */
    void gl_draw_button(int id, buttons_l **buttons, window_s *window);

    /**
     * @brief Check if a button is hovered
     * @param buttons Buttons list
     * @param window Window struct
     */
    void gl_buttons_hovered(buttons_l **buttons, window_s *window);

    /**
     * @brief Change button state (disabled or not)
     * @param id Button id
     * @param buttons Buttons list
     * @param state State of the button (sfTrue or sfFalse)
     */
    void gl_button_change_state(int id, buttons_l **buttons, sfBool state);

#endif
