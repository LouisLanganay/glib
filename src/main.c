/*
** EPITECH PROJECT, 2023
** glib
** File description:
** main
*/

#include "main.h"
#include "gl.h"

void event_window_close(window_t *window)
{
    sfRenderWindow_close(window->window);
}

void test(int id)
{
    printf("test\n");
}

int main(void)
{
    GLib_t *glib = malloc(sizeof(GLib_t));
    glib->window = gl_create_window(1920, 1080, "My window", 60);
    glib->events = NULL;
    glib->buttons = NULL;
    glib->scenes = NULL;
    glib->sprites = NULL;
    glib->texts = NULL;
    gl_create_event(glib, 544, sfEvtClosed, event_window_close);
    gl_create_event(glib, 888, sfEvtKeyPressed, event_window_close);



    buttons_t *my_btn = malloc(sizeof(buttons_t));
    my_btn->id = 1;
    my_btn->pos = (sfVector2f){0, 0};
    my_btn->sprite = sfSprite_create();
    my_btn->texture = sfTexture_createFromFile("assets/btn/t.png", NULL);
    my_btn->rect = (sfIntRect){0, 0, 100, 100};
    my_btn->call_action = test;
    my_btn->sb_click = sfSoundBuffer_createFromFile("assets/btn/button1.ogg");
    my_btn->sb_hover = sfSoundBuffer_createFromFile("assets/btn/button2.ogg");
    gl_create_button(glib, my_btn);
    gl_create_scene(glib, 1);
    gl_add_button_to_scene(glib, 1, 1);

    sprite_t *my_sprite = malloc(sizeof(sprite_t));
    my_sprite->id = 1;
    my_sprite->pos = (sfVector2f){0, 0};
    my_sprite->sprite = sfSprite_create();
    my_sprite->texture = sfTexture_createFromFile("/home/peron/glib/src/cross.png", NULL);
    my_sprite->scale = (sfVector2f){1, 1};
    my_sprite->call_action = NULL;
    gl_create_sprite(glib, my_sprite);

    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = 1;
    my_text->pos = (sfVector2f){0, 0};
    my_text->text = sfText_create();
    my_text->font = sfFont_createFromFile("/home/peron/glib/src/OpenSans-Regular.ttf");
    my_text->string = "Hello world";
    my_text->size = 50;
    my_text->color = sfWhite;
    my_text->scale = (sfVector2f){1, 1};
    gl_create_text(glib, my_text);


    while (sfRenderWindow_isOpen(glib->window->window)) {
        gl_draw_scene(glib, 1);
        gl_buttons_hovered(glib->buttons, glib->window);
        gl_check_events(glib->window, glib->events);
        gl_draw_sprites(glib);
        gl_draw_texts(glib);
        sfClock_restart(glib->window->clock);
        sfRenderWindow_display(glib->window->window);
        sfRenderWindow_clear(glib->window->window, sfBlack);
    }

}
