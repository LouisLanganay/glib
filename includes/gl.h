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

    int gl_create_button(GLib_t *glib, buttons_t *button);

    void gl_draw_button(int id, buttons_t *buttons, window_t *window);

    void gl_buttons_hovered(buttons_t *buttons, window_t *window);

    void gl_button_change_state(int id, buttons_t *buttons, sfBool state);

    int gl_create_scene(GLib_t *glib, int id);

    int gl_add_button_to_scene(GLib_t *glib, int scene_id, int button_id);

    void gl_draw_scene(GLib_t *glib, int id);

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
    void gl_draw_sprites(window_t *window, sprite_t *sprites);

    /**
     * @brief draw sprite id
     * @param window
     * @param sprites
     * @param id
     */
    void gl_draw_sprite(window_t *window, sprite_t *sprites, int id);

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
    void gl_draw_texts(window_t *window, text_t *texts);

    /**
     * @brief draw text id
     * @param window
     * @param texts
     * @param id
     */
    void gl_draw_text(window_t *window, text_t *texts, int id);
#endif
