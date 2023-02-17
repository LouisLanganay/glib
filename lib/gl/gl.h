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


    typedef struct window_s {
        sfRenderWindow* window;
        sfVideoMode mode;
        sfClock* clock;
        sfEvent event;
    } window_t;

    typedef struct events_l {
        int id;
        sfEventType type;
        void (*event)(window_t *window);
        struct events_l *next;
    } events_t;

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
    } buttons_t;

    typedef struct sprite_s {
        int id;
        sfVector2f pos;
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f scale;
        void (*call_action)(void *sprite);
        struct sprite_s *next;
    } sprite_t;

    typedef struct scenes_l {
        int id;
        int *buttons;
        int *texts;
        int *sprites;
        struct scenes_l *next;
    } scenes_t;

    typedef struct text_s {
        int id;
        sfVector2f pos;
        sfText *text;
        sfFont *font;
        sfColor color;
        sfVector2f scale;
        char *string;
        int size;
        struct text_s *next;
    } text_t;

    typedef struct GLib_s {
        window_t *window;
        events_t *events;
        buttons_t *buttons;
        scenes_t *scenes;
        sprite_t *sprites;
        text_t *texts;
    } GLib_t;



    window_t *gl_create_window(
        int width,
        int height,
        char *title,
        int framerate
    );

    int gl_create_event(
        GLib_t *glib,
        int id,
        sfEventType type,
        void (*event)(window_t *window)
    );

    void gl_check_events(window_t *window, events_t *events);

    void gl_delete_event(GLib_t *glib, int id);

    void gl_delete_events(GLib_t *glib);

    int gl_create_button(GLib_t *glib, buttons_t *button);

    void gl_delete_buttons(GLib_t *glib);

    void gl_delete_button(GLib_t *glib, int id);

    void gl_draw_button(int id, buttons_t *buttons, window_t *window);

    void gl_buttons_hovered(buttons_t *buttons, window_t *window);

    void gl_button_change_state(int id, buttons_t *buttons, sfBool state);

    int gl_create_scene(GLib_t *glib, int id);

    void gl_delete_scene(GLib_t *glib, int id);

    void gl_delete_scenes(GLib_t *glib);

    int gl_add_button_to_scene(GLib_t *glib, int scene_id, int button_id);

    void gl_draw_scene(GLib_t *glib, int id);

    int gl_create_sprite(GLib_t *glib, sprite_t *sprite);

    void gl_draw_sprites(GLib_t *glib);

    void gl_draw_sprite(GLib_t *glib, int id);

    void gl_delete_sprite(GLib_t *glib, int id);

    void gl_delete_sprites(GLib_t *glib);

    int gl_create_text(GLib_t *glib, text_t *text);

    void gl_delete_text(GLib_t *glib, int id);

    void gl_delete_texts(GLib_t *glib);

    void gl_draw_texts(GLib_t *glib);

    void gl_draw_text(GLib_t *glib, int id);
#endif
