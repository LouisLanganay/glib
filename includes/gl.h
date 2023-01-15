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

    #define SCENE_ARRAY_SIZE 100;


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
     * @brief scenes_l struct for scenes management
     */
    typedef struct scenes_l {
        int id;
        int *buttons;
        int *texts;
        int *sprites;
        struct scenes_l *next;
    } scenes_t;

    /**
     * @brief GLib_t struct for glib management
     */
    typedef struct GLib_s {
        window_s *window;
        events_l *events;
        buttons_l *buttons;
        scenes_t *scenes;
    } GLib_t;




    window_s *gl_create_window(
        int width,
        int height,
        char *title,
        int framerate
    );

    int gl_create_event(
        GLib_t *glib,
        int id,
        sfEventType type,
        void (*event)(window_s *window)
    );

    void gl_check_events(window_s *window, events_l *events);

    int gl_create_button(GLib_t *glib, buttons_l *button);

    void gl_draw_button(int id, buttons_l *buttons, window_s *window);

    void gl_buttons_hovered(buttons_l *buttons, window_s *window);

    void gl_button_change_state(int id, buttons_l *buttons, sfBool state);

    int gl_create_scene(GLib_t *glib, int id);

    int gl_add_button_to_scene(GLib_t *glib, int scene_id, int button_id);

    void gl_draw_scene(GLib_t *glib, int id);

#endif
