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
     * @brief button_s struct for button management
     */
    typedef struct button_s {
        int id;
        sfVector2f pos;
        sfConvexShape *shape;
        sfTexture *texture;
        void (*call_action)(void *button);
        struct button_s *next;
    } button_s;

    /**
     * @brief sprite_s struct for sprite management
     * @param id Sprite id
     * @param pos Sprite position
     * @param sprite Sprite
     * @param texture Sprite texture
     * @param scale Sprite scale
     * @param call_action Function to call when sprite is clicked
     */
    typedef struct sprite_s {
        int id;
        sfVector2f pos;
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f scale;
        void (*call_action)(void *sprite);
        struct sprite_s *next;
    } sprite_t;


    /**
     * @brief text_s struct for text management
     * @param id Text id
     * @param pos Text position
     * @param text Text
     * @param font Text font
     * @param scale Text scale
     */
    typedef struct text_s {
        int id;
        sfVector2f pos;
        sfText *text;
        sfFont *font;
        sfColor color;
        sfVector2f scale;
        char *string;
        struct text_s *next;
    } text_t;



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

    /**
     * @brief create button
     * @param buttons Buttons list
     * @param button Button struct to create
     */
    void gl_create_button(button_s **buttons, button_s *button);

    /**
     * @brief create sprite
     * @param sprites Sprites list
     * @param sprite Sprite struct to create
     * @return int Return 0 if success, 84 if error
     */
    int gl_create_sprite(sprite_t **sprites, sprite_t *sprite);

    /**
     * @brief draw sprites
     * @param window Window struct
     * @param sprites Sprites list
     */
    void gl_draw_sprites(window_s *window, sprite_t *sprites);

    /**
     * @brief draw sprite id
     * @param window
     * @param sprites
     * @param id
     */
    void gl_draw_sprite(window_s *window, sprite_t *sprites, int id);

    /**
     * @brief delete sprite id
     * @param sprites Sprites list
     * @param id Sprite id
     */
    void gl_delete_sprite(sprite_t **sprites, int id);

    /**
     * @brief delete sprites
     * @param sprites Sprites list
     */
    void gl_delete_sprites(sprite_t **sprites);

    /**
     * @brief
     * @param texts
     * @param text
     * @return int
     */
    int gl_create_text(text_t **texts, text_t *text);

    /**
     * @brief delete text id
     * @param texts
     * @param id
     */
    void gl_delete_text(text_t **texts, int id);

    /**
     * @brief delete texts
     * @param texts
     */
    void gl_delete_texts(text_t **texts);

    /**
     * @brief draw texts
     * @param window
     * @param texts
     */
    void gl_draw_texts(window_s *window, text_t *texts);

    /**
     * @brief draw text id
     * @param window
     * @param texts
     * @param id
     */
    void gl_draw_text(window_s *window, text_t *texts, int id);
#endif
